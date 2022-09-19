using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class ClockForUnityGames_Template.cs : MonoBehaviour
{
    //1 minute IN = 1 second OUT
    //1 hour IN = 1 minute OUT
    //Text Mesh Pro is needed if you don't want to rewrite anything
    public TextMeshProUGUI timeText;
    public int hours = 0;
    public int minutes = 0;
    public int day = 1;
    public string strHours = "0"; 
    public string strMinutes = "0";

    void Update()
    {
        #region TimeCalculator
        minutes = (int)Time.time - ((60 * hours) + ((day-1) * 24 * 60)) ;
       if(minutes==60){
        hours++;
       }
       if(hours == 24){
        day++;
        hours = 0;
       }
       if(hours<=9){
        strHours = "0" + hours;
       }else{
        strHours = hours.ToString();
       }
       if(minutes<=9){
        strMinutes = "0" + minutes;
       }else{
        strMinutes = minutes.ToString();
       }
       timeText.text = "Day " + day + " " + strHours + ":" + strMinutes;
       #endregion 
    }
}
