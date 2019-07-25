using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEditor;
using UnityEditor.SceneManagement;

public class LectureTool : EditorWindow
{
    Mesh sourceMesh;
    Material sourceMaterial;
    float scaleFactor;
    private void OnGUI()
    {
        sourceMesh = (Mesh)EditorGUILayout.ObjectField("Source Mesh", sourceMesh, typeof(Mesh), false);
        sourceMaterial = (Material)EditorGUILayout.ObjectField("Source Material", sourceMaterial, typeof(Material), false);
        scaleFactor = EditorGUILayout.Slider("Slider Factor", scaleFactor, 0.1f, 5);
        if (GUILayout.Button("Apply"))
        {
            Debug.Log("Apply");
            //var mesh = Instantiate(sourceMesh);
            var mesh = sourceMesh;
            Undo.RecordObject(mesh, "Double size");
            var vertices = new Vector3[mesh.vertexCount];
            for (int i = 0; i < mesh.vertexCount; i++)
            {
                vertices[i] = mesh.vertices[i] * scaleFactor;
            }
            sourceMesh.vertices = vertices;
            EditorUtility.SetDirty(sourceMesh);
            AssetDatabase.SaveAssets();
            //AssetDatabase.CreateAsset(mesh, "Assets/mesh1.asset");
        }
        if (GUILayout.Button("Create Prefab"))
            EditorApplication.delayCall += () =>
        {
            Debug.Log("Create");
            var go = new GameObject(sourceMesh.name);
            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = sourceMesh;
            var mr = go.AddComponent<MeshRenderer>();
            mr.sharedMaterial = sourceMaterial;
            PrefabUtility.SaveAsPrefabAsset(go, "Assets/cube.prefab");
            DestroyImmediate(go);
        };
    }


    [MenuItem("Lecture/Write Texture")]
    static void WriteTexture()
    {
        const int N = 512;
        var tex = new Texture2D(N, N, TextureFormat.RGB24, false);
        var pixels = new Color[N * N];
        for (int i = 0; i < N * N; i++)
        {
            pixels[i] = Color.red;
        }
        tex.SetPixels(pixels);
        var bytes = ImageConversion.EncodeToPNG(tex);
        System.IO.File.WriteAllBytes("Assets/red.png", bytes);
        AssetDatabase.Refresh();
        var importer = (TextureImporter)AssetImporter.GetAtPath("Assets/red.png");
        importer.mipmapEnabled = false;
        importer.SaveAndReimport();
    }


    [MenuItem("Lecture/Create Atlas")]
    static void TextureAtlas()
    {
        var go = Selection.activeGameObject;
        var meshRenderers = go.GetComponentsInChildren<MeshRenderer>();
        var textures = new List<Texture2D>();
        foreach (var mr in meshRenderers)
        {
            textures.Add((Texture2D)mr.sharedMaterial.mainTexture);
        }
        var tex = new Texture2D(0, 0);
        var rects = tex.PackTextures(textures.ToArray(), 1);
        foreach (var r in rects)
            Debug.Log(r);
        var bytes = ImageConversion.EncodeToPNG(tex);
        System.IO.File.WriteAllBytes("Assets/red.png", bytes);
        AssetDatabase.Refresh();
    }


    [MenuItem("Lecture/Show Window")]
    static void ShowWindow()
    {
        var win = GetWindow<LectureTool>();
        win.Show();
    }

    [MenuItem("Lecture/Combine Meshes")]
    static void CombineMeshes()
    {
        Debug.Log("Combine Meshes");
        var root = Selection.activeGameObject;
        //获取所有子物体的网格
        MeshFilter[] meshFilters = root.GetComponentsInChildren<MeshFilter>();
        int capcity = meshFilters.Length;
        CombineInstance[] combine = new CombineInstance[capcity];

        //获取所有子物体的渲染器和材质
        MeshRenderer[] meshRenderers = root.GetComponentsInChildren<MeshRenderer>();
        Material[] materials = new Material[capcity];

        //生成新的渲染器和网格组件
        var combineObject = new GameObject();
        MeshRenderer meshRenderer = root.gameObject.AddComponent<MeshRenderer>();
        MeshFilter meshFilter = root.gameObject.AddComponent<MeshFilter>();
        Debug.Log(capcity);
        //合并子纹理
        Texture2D[] textures = new Texture2D[capcity];
        for (int i = 0; i < capcity; i++)
        {
            if (meshFilters[i].transform != root.transform)
            {
                Debug.Log(i);
                materials[i] = meshRenderers[i].sharedMaterial;
                Texture2D tx = materials[i].GetTexture("_MainTex") as Texture2D;
                Texture2D tx2D = new Texture2D(tx.width, tx.height, TextureFormat.ARGB32, false);
                tx2D.SetPixels(tx.GetPixels(0, 0, tx.width, tx.height));
                tx2D.Apply();
                textures[i] = tx2D;
            }
        }

        //生成新的材质
        Material materialNew = new Material(materials[0].shader);
        materialNew.CopyPropertiesFromMaterial(materials[0]);
        meshRenderer.sharedMaterial = materialNew;

        //设置新材质的主纹理
        Texture2D texture = new Texture2D(1024, 1024);
        materialNew.SetTexture("_MainTex", texture);
        Rect[] rects = texture.PackTextures(textures, 10, 1024);

        //根据纹理合并的信息刷新子网格UV
        for (int i = 0; i < meshFilters.Length; i++)
        {
            if (meshFilters[i].transform == root.transform)
            {
                continue;
            }
            Rect rect = rects[i];

            Mesh meshCombine = meshFilters[i].sharedMesh;
            Vector2[] uvs = new Vector2[meshCombine.uv.Length];
            //把网格的uv根据贴图的rect刷一遍  
            for (int j = 0; j < uvs.Length; j++)
            {
                uvs[j].x = rect.x + meshCombine.uv[j].x * rect.width;
                uvs[j].y = rect.y + meshCombine.uv[j].y * rect.height;
            }
            meshCombine.uv = uvs;
            combine[i].mesh = meshCombine;
            combine[i].transform = meshFilters[i].transform.localToWorldMatrix;
            meshFilters[i].gameObject.SetActive(false);
        }

        //生成新的网格，赋值给新的网格渲染组件
        Mesh newMesh = new Mesh();
        newMesh.CombineMeshes(combine, true, true);//合并网格  
        meshFilter.sharedMesh = newMesh;
    }


    [MenuItem("Lecture/Test")]
    static void Test()
    {
        Debug.Log(Selection.activeObject);
        var meshFilter = Selection.activeGameObject.GetComponent<MeshFilter>();
        Debug.Log(meshFilter.sharedMesh);
        //if (AssetDatabase.FindAssets(Selection.activeObject.name) == null)
        var mesh = Instantiate(meshFilter.sharedMesh);
        AssetDatabase.CreateAsset(mesh, "Assets/mesh.asset");
    }
}
