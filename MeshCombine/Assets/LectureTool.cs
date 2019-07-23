using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

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
        var pixels = new Color[N];
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


    [MenuItem("Lecture/Test")]
    static void Test()
    {
        Debug.Log(Selection.activeObject);
        var meshFilter = Selection.activeGameObject.GetComponent<MeshFilter>();
        Debug.Log(meshFilter.sharedMesh);
        if (AssetDatabase.FindAssets(Selection.activeObject.name) == null)
            AssetDatabase.CreateAsset(meshFilter.sharedMesh, "Assets/mesh.asset");
    }
}
