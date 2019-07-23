using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TestCoroutine : MonoBehaviour
{

    private int total = 30;
    private int num = 0;

    IEnumerator Test()
    {
        while (num < total)
        {
            num++;
            Debug.Log(num);
            yield return null;
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(Test());
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log("update");
    }

    void LateUpdate()
    {
        Debug.Log("late update");
    }
}
