package com.example.lab2

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        button.setOnClickListener { startActivity(Intent(this, picture::class.java)) }
        button2.setOnClickListener { startActivity(Intent(this, table::class.java)) }
        button3.setOnClickListener { startActivity(Intent(this, list::class.java)) }
    }
}
