using UnityEngine;
using System.Collections;

public class Player : MonoBehaviour {

    private new Rigidbody2D rigidbody;
    private Animator animator;


	// Use this for initialization
	void Start () {
	    rigidbody = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
	}

    void Update() {
        if(Input.GetButtonDown("Use")) {
            RaycastHit2D[] hits = Physics2D.BoxCastAll(transform.position, new Vector2(64, 64), 0, Vector2.zero);
            if(hits.Length > 0) {
                Debug.Log(hits.Length + " hits");
            }
        }
    }

	void FixedUpdate() {

        if(Input.GetAxis("Horizontal") < 0) {
            animator.SetInteger("MoveDirection", 4);
        }
        else if(Input.GetAxis("Horizontal") > 0) {
            animator.SetInteger("MoveDirection", 2);
        }

		if(Input.GetAxis("Vertical") < 0) {
            animator.SetInteger("MoveDirection", 1);
		}
        else if(Input.GetAxis("Vertical") > 0) {
            animator.SetInteger("MoveDirection", 3);
        }

        if(rigidbody.velocity.magnitude > 0) {
            animator.SetBool("Moving", true);
        }
        else {
            animator.SetBool("Moving", false);
        }

        rigidbody.velocity = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical")) * 2;
	}

    void LateUpdate() {
        transform.position = new Vector3((int)(transform.position.x / 0.001f) * 0.001f, (int)(transform.position.y / 0.001f) * 0.001f, transform.position.z);
    }
}
