using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Cinemachine;

public class MovementController3D_Template : MonoBehaviour
{
    public CharacterController characterController;
    public GameObject Player;
    public GameObject DeathMenu;
    public AudioSource walkingFz; //sound player makes when walking
    public Animator animator;
    public Transform cam; //used for camera relative movement
    public Transform groundCheck;
    public float groundDistance = 3f; //better to modify for every character
    public float speed = 8.0f; //better to modify for every character
    public float turnSmoothTime = 0.1f; //better to modify for every character
    public float pushForce = 5f; //better to modify for every character
    float turnSmoothVelocity, targetAngle, verticalSpeed;
    public bool isGrounded;
    public bool dead = false;
    public LayerMask groundMask;
    Vector3 moveDirection;
    public Vector3 velocity;

    void Start()
    {
        CinemachineCore.GetInputAxis = GetAxisCustom;
    }
    public float GetAxisCustom(string axisName)
    {
        if (axisName == "Mouse X")
        {
            if (Input.GetMouseButton(1)) return UnityEngine.Input.GetAxis("Mouse X");
            else return 0;
        }
        return UnityEngine.Input.GetAxis(axisName);
    }

    void Update(){
        Player.transform.position = new Vector3(Player.transform.position.x, heightToKeep.y, Player.transform.position.z);
        isGrounded = Physics.CheckSphere(groundCheck.position, groundDistance, groundMask);
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");
        moveDirection = new Vector3(horizontal, 0f, vertical).normalized;
        if (moveDirection.magnitude >= 0.1f){ //smooth movement using Euler angles
            targetAngle = Mathf.Atan2(moveDirection.x, moveDirection.z) * Mathf.Rad2Deg + cam.eulerAngles.y;
            float angle = Mathf.SmoothDampAngle(transform.eulerAngles.y, targetAngle, ref turnSmoothVelocity, turnSmoothTime);
            transform.rotation = Quaternion.Euler(0f, angle, 0f);

            Vector3 direction = Quaternion.Euler(0f, targetAngle, 0f) * Vector3.forward;
            characterController.Move(direction.normalized * speed * Time.deltaTime);
            characterController.Move(velocity * Time.deltaTime);
        }
        if(moveDirection.magnitude >= 0.1f) animator.SetBool("IsMoving", true);
        else{
            animator.SetBool("IsMoving", false);
            bool AudioIsPaused = false;
        } 
        #region SoundControl
        if (Input.GetButtonDown("Horizontal") ||
        Input.GetButtonDown("Vertical") && !walkingFz.isPlaying && isGrounded == true){
            walkingFz.Play();
        }
        else if (!Input.GetButton("Horizontal") && !Input.GetButton("Vertical") && walkingFz.isPlaying){
            walkingFz.Stop();
        }
        else if (walkingFz.isPlaying && isGrounded == false){
            walkingFz.Pause();
            AudioIsPaused = true;
        }
        if (AudioIsPaused == true && isGrounded == true && (Input.GetButton("Horizontal") || Input.GetButton("Vertical"))){
            walkingFz.UnPause();
        }
        #endregion
    }
    void OnControllerColliderHit(ControllerColliderHit hit){ //lets player interact with physical objects that have rigibody attached
        Rigidbody body = hit.collider.attachedRigidbody;
        if (body == null || body.isKinematic || hit.moveDirection.y < -0.3f) return;
        Vector3 pushDirection = new Vector3(hit.moveDirection.x, 0, hit.moveDirection.z);

        body.velocity = pushDirection * pushForce;
    }
    void Death() //calls death menu and logically kills player, can be removed
    {
        if(!dead)
        {
            Debug.Log("Dead");
            DeathMenu.SetActive(true);
            dead = true;
            Time.timeScale = 0f;
        }
    }
}
