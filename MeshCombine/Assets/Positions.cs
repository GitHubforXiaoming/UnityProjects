using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System;

public class Positions : ScriptableObject
{
    [Serializable]
    public class NamePosition
    {
        [SerializeField]
        public string name;
        [SerializeField]
        public Vector3 position;
    }

    public Vector3[] positions;

    [MenuItem("Lecture/Create Positions")]
    static void CreatePositions()
    {
        var go = Selection.activeGameObject;
        var trs = go.GetComponentsInChildren<Transform>();
        var result = new Positions();
        var ps = result.positions = new Vector3[trs.Length];
        for (int i = 0; i < trs.Length; i++)
            ps[i] = trs[i].position;
        AssetDatabase.CreateAsset(result, "Assets/positions.asset");
    }
}
