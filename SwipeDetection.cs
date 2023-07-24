using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class Swipe : MonoBehaviour, IEndDragHandler, IBeginDragHandler, IDragHandler{
    public enum DraggedDirection{Up,Down,Right,Left}

    public void OnEndDrag(PointerEventData eventData){
        Vector3 dragVectorDirection = (eventData.position - eventData.pressPosition).normalized;
        MovePlayer(GetDragDirection(dragVectorDirection));
    }
    public void OnBeginDrag(PointerEventData eventData){}
    public void OnDrag(PointerEventData eventData){}
   
public DraggedDirection GetDragDirection(Vector3 dragVector){
    float positiveX = Mathf.Abs(dragVector.x);
    float positiveY = Mathf.Abs(dragVector.y);
    DraggedDirection draggedDir;
    if (positiveX > positiveY){
        draggedDir = (dragVector.x > 0) ? DraggedDirection.Right : DraggedDirection.Left;
    }
    else{
        draggedDir = (dragVector.y > 0) ? DraggedDirection.Up : DraggedDirection.Down;
    }
        // Debug.Log(draggedDir);
        return draggedDir;
    }
}
