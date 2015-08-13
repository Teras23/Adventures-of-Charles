﻿using UnityEngine;
using System.Collections;

public class Player : MonoBehaviour {

    int moveDirection;
    private new Rigidbody2D rigidbody;


	// Use this for initialization
	void Start () {
	    rigidbody = GetComponent<Rigidbody2D>();
	}
	
	void FixedUpdate() {
		moveDirection = 0;
		if(Input.GetAxis("Vertical") < 0) {
			moveDirection = 2;
		}
		//animator.SetInteger("MoveDirection", moveDirection);

        rigidbody.velocity = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));

		//Move();
	}

    void LateUpdate() {
        //transform.position = new Vector3((int)(transform.position.x / 0.01f) * 0.01f, (int)(transform.position.y / 0.01f) * 0.01f, transform.position.z);
    }

    void Move() {
        if(moveDirection == 2) {
            
            transform.position = new Vector2(transform.position.x, transform.position.y - 0.01f);
        }
    }
}
