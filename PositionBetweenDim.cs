using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PositionBetweenDim : MonoBehaviour
{
    public GameObject Bound2DObject;
    public GameObject Bound3DObject;

    public Vector3 firstPositionIn2D;
    public Vector3 secondPositionIn2D;
    public Vector3 firstPositionIn3D;
    public Vector3 secondPositionIn3D;

    Vector3 axisChange;

    void Start()
    {
        firstPositionIn2D = Bound2DObject.transform.position;
        firstPositionIn3D = Bound3DObject.transform.position;
    }
    public void CheckPosition(int Dimensions)
    {
        Debug.Log("position check");
        if (Dimensions == 2)
        {
            secondPositionIn2D = Bound2DObject.transform.position;
            axisChange.x = secondPositionIn2D.x - firstPositionIn2D.x;
            axisChange.y = secondPositionIn2D.y - firstPositionIn2D.y;
            Bound3DObject.transform.position = new Vector3(Bound3DObject.transform.position.x + axisChange.x,
                Bound3DObject.transform.position.y + axisChange.y,
                Bound3DObject.transform.position.z);
            Debug.Log("positionsSwapped2D " + axisChange.x + "axisChange.y = " + axisChange.y + " secondPositionIn2D.x " + secondPositionIn2D.x + " first " + firstPositionIn2D.x);
            firstPositionIn2D = secondPositionIn2D;
            firstPositionIn3D = Bound3DObject.transform.position;
            axisChange = new Vector3(0f, 0f, 0f);
        }
        else if (Dimensions == 3)
        {
            secondPositionIn3D = Bound3DObject.transform.position;
            axisChange.x = secondPositionIn3D.x - firstPositionIn3D.x;
            axisChange.y = secondPositionIn3D.y - firstPositionIn3D.y;
            Bound2DObject.transform.position = new Vector3(Bound2DObject.transform.position.x + axisChange.x,
                Bound2DObject.transform.position.y + axisChange.y,
                Bound2DObject.transform.position.z);
            Debug.Log("positionsSwapped3D axisChange.x =" + axisChange.x + "axisChange.y = " + axisChange.y);
            firstPositionIn3D = secondPositionIn3D;
            firstPositionIn2D = Bound2DObject.transform.position;
            axisChange = new Vector3(0f, 0f, 0f);
        }
        else
        {
            Debug.Log("Failed getting dimensions");
        }
    }
}
