package com.example.lab2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.ListAdapter
import android.widget.ListView
import com.example.lab2.list
import kotlinx.android.synthetic.main.activity_list.*

class list : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_list)
        val lst = listOf("Серёга", "Лёха", "Алдынай", "Костенко", "Настя",
            "Денис", "Петя", "Рустам", "Захар", "Артур")
        list.adapter = ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, lst)
    }
}
