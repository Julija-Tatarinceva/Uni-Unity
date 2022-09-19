using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.CrossPlatformInput;

public class CPIPlayerMovement2D : MonoBehaviour
{
    [Range(0, .3f)] [SerializeField] private float m_MovementSmoothing = .05f;
    [SerializeField] private LayerMask WhatIsGround;
    const float k_GroundedRadius = .3f;
    [SerializeField] private Transform m_GroundCheck;
    private Vector3 m_Velocity = Vector3.zero;
    public Animator animator;
    private Rigidbody2D m_Rigidbody2D;
    public float runSpeed = 50f;
    float horizontalMove = 0f;
    bool AudioIsPaused = false;
    public bool jump = false;
    private bool m_FacingRight = true;
    public GameObject Player;
    void Awake()
    {
        m_Rigidbody2D = GetComponent<Rigidbody2D>();
    }
    void Update()
    {
        horizontalMove = CrossPlatformInputManager.GetAxis("Horizontal") * runSpeed;
        Debug.Log("rawAxis = " + horizontalMove / runSpeed);
       animator.SetFloat("Speed", Mathf.Abs(horizontalMove));
        if (Input.GetButtonDown("Jump") && jump == false)
        {
            jump = true;
        }
    }
    public void OnLanding()
    {
        //animator.SetBool("IsJumping", false);
    }
    void FixedUpdate()
    {
        bool m_Grounded = false;
        bool wasGrounded = m_Grounded;
        m_Grounded = false;
        Collider2D[] colliders = Physics2D.OverlapCircleAll(m_GroundCheck.position, k_GroundedRadius, WhatIsGround);
        for (int i = 0; i < colliders.Length; i++)
        {
            if (colliders[i].gameObject != gameObject)
            {
                m_Grounded = true;
            }
        }
        Vector3 targetVelocity = new Vector2(horizontalMove * Time.fixedDeltaTime * 10f, m_Rigidbody2D.velocity.y);
        m_Rigidbody2D.velocity = Vector3.SmoothDamp(m_Rigidbody2D.velocity, targetVelocity, ref m_Velocity, m_MovementSmoothing);
        if (horizontalMove > 0 && !m_FacingRight)
        {
            Flip();
        }
        else if (horizontalMove < 0 && m_FacingRight)
        {
            Flip();
        }
        if (m_Grounded && jump)
        {
            m_Rigidbody2D.AddForce(new Vector2(0f, 140 * 1.3f));
            m_Grounded = false;
            jump = false;
        }
    }
    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.tag == "Deadly")
        {
            Debug.Log("dead");
        }
    }
    private void Flip()
    {
        m_FacingRight = !m_FacingRight;
        transform.Rotate(0f, 180f, 0f);
    }
}