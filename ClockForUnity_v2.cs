using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class TimeCalculator : MonoBehaviour{
    public TextMeshProUGUI timeText;
    private int _minutes = 0;
    private int _seconds = 0;
    string _strMinutes = "0"; 
    string _strSeconds = "0";
    public float timePassed = 0;
    // Start is called before the first frame update
    void Start(){
        minutes = 0;
        seconds = 0;
    }

    // Update is called once per frame
    void Update(){
        #region TimeCalculator
        timePassed += Time.deltaTime; // Fetching time that has passed since the last frame and adding it to the sum
            // Using math to output the time in seconds using minutes:seconds format
            _seconds = (int)timePassed - (60 * _minutes);
            if(_seconds==60) {
                // Adding another minute to the timer
                _minutes++;
                _strMinutes = _minutes switch {
                    >= 9 => _minutes.ToString(),
                    < 9 => "0" + _minutes
                };
            }
            _strSeconds = _seconds switch {
                <=9 => "0" + _seconds,
                _ => _seconds.ToString()
            };
            timeText.text = _strMinutes + ":" + _strSeconds;
       #endregion
    }
}
