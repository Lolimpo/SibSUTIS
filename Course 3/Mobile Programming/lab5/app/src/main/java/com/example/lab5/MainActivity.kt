package com.example.lab5

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.*


class MainActivity : AppCompatActivity() {

    var lst: MutableList<Student> = ArrayList()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        filldb()

        val table = TableLayout(this)

        table.isStretchAllColumns = true
        table.isShrinkAllColumns = true

        val rows = Array(100, {TableRow(this)})

        val empty = TextView(this)

        for ((i, stud) in lst.withIndex()) {
            val disName = TextView(this)
            val disAge = TextView(this)
            val disWeight = TextView(this)
            disName.text = lst[i].name
            disAge.text = lst[i].age.toString()
            disWeight.text = lst[i].weight.toString()
            rows[i].addView(disName)
            rows[i].addView(disAge)
            rows[i].addView(disWeight)
            table.addView(rows[i])
        }

        setContentView(table)
    }

    private fun filldb()
    {
        val student1 = Student("Igor", 18, (50..100).random())
        val student2 = Student("Nikolai", 20, (50..100).random())
        val student3 = Student("Andrew", 21, (50..100).random())
        val student4 = Student("Vladimir", 30, (50..100).random())
        val student5 = Student("Alina", 20, (50..100).random())
        val student6 = Student("Sasha", 19, (50..100).random())

        val db = DatabaseHandler(this)

        db.addStudent(student1)
        db.addStudent(student2)
        db.addStudent(student3)
        db.addStudent(student4)
        db.addStudent(student5)
        db.addStudent(student6)

        lst = db.readDB()
    }
}
