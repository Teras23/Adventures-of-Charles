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

        rigidbody.velocity = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));

        //0.002485712

        if(rigidbody.velocity.magnitude > 0) {
            animator.SetBool("Moving", true);
        }
        else {
            animator.SetBool("Moving", false);
        }
	}

    void LateUpdate() {
        transform.position = new Vector3((int)(transform.position.x / 0.001f) * 0.001f, (int)(transform.position.y / 0.001f) * 0.001f, transform.position.z);
    }
}
