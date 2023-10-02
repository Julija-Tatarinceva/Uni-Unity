using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class Overlord : MonoBehaviour
{
    public TextMeshProUGUI ScoreText;
    public TextMeshProUGUI timeText;
    public int minutes = 0;
    public int seconds = 0;
    string strMinutes = "0"; 
    string strSeconds = "0";
    public float TimePassed = 0;
    public int score = 0;
    // Start is called before the first frame update
    void Start()
    {
        minutes = 0;
        seconds = 0;
    }

    // Update is called once per frame
    void Update()
    {
        #region TimeCalculator
        TimePassed += Time.deltaTime;
        seconds = (int)TimePassed - (60 * minutes);
        if(minutes==60){
            minutes++;
            if(minutes<=9) strMinutes = "0" + minutes;
            else strMinutes = minutes.ToString();
        }
       if(seconds<=9) strSeconds = "0" + seconds;
       else strSeconds = seconds.ToString();
       timeText.text = strMinutes + ":" + strSeconds;
       #endregion
    }
    public void UpdateGUI(){
        ScoreText.text = "Score:" + score.ToString();
    }
}
