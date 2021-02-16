package com.example.lab0

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    var num = arrayListOf<Long>(0, 0, 0)
    var i = 0
    val err = "Error"
    var temp: String? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        button.setOnClickListener{
            num[i] = num[i] * 10 + 1
            textView.text = num[i].toString()
        }
        button2.setOnClickListener{
            num[i] = num[i] * 10 + 2
            textView.text = num[i].toString()
        }
        button3.setOnClickListener{
            num[i] = num[i] * 10 + 3
            textView.text = num[i].toString()
        }
        button6.setOnClickListener{
            num[i] = num[i] * 10 + 6
            textView.text = num[i].toString()
        }
        button7.setOnClickListener{
            num[i] = num[i] * 10 + 5
            textView.text = num[i].toString()
        }
        button8.setOnClickListener{
            num[i] = num[i] * 10 + 4
            textView.text = num[i].toString()
        }
        button9.setOnClickListener{
            num[i] = num[i] * 10 + 7
            textView.text = num[i].toString()
        }
        button10.setOnClickListener{
            num[i] = num[i] * 10 + 8
            textView.text = num[i].toString()
        }
        button11.setOnClickListener{
            num[i] = num[i] * 10 + 9
            textView.text = num[i].toString()
        }
        button14.setOnClickListener{
            num[i] = num[i] * 10 + 0
            textView.text = num[i].toString()
        }
        button13.setOnClickListener{
            num[0] = 0
            num[1] = 0
            num[2] = 0
            textView.text = "0"
        }
        button4.setOnClickListener{
            temp = "+"
            i = 1
            textView.text = "0"
        }
        button5.setOnClickListener {
            temp = "-"
            i = 1
            textView.text = "0"
        }
        button12.setOnClickListener {
            temp = "*"
            i = 1
            textView.text = "0"
        }
        button16.setOnClickListener {
            temp = "/"
            i = 1
            textView.text = "0"
        }
        button15.setOnClickListener {
            var divRes: Double = 0.0
            i = 0
            when (temp) {
                "+" -> num[2] = num[0] + num[1]
                "-" -> num[2] = num[0] - num[1]
                "*" -> num[2] = num[0] * num[1]
                "/" ->
                    if(num[1] != 0L)
                        if (num[0] % num[1] != 0L)
                            divRes = num[0].toDouble() / num[1].toDouble()
                        else
                            num[2] = num[0] / num[1]
            }
            if(num[1] != 0L)
                if (num[2] == 0L)
                    textView.text = divRes.toString()
                else
                    textView.text = num[2].toString()
            else
                textView.text = err
        }
    }
}
