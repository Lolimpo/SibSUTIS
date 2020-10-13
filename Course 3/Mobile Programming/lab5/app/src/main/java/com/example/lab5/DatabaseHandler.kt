package com.example.lab5

import android.content.ContentValues
import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import android.util.Log

class DatabaseHandler(var context: Context) :
        SQLiteOpenHelper(context, DB_NAME, null, DB_VERSIOM) {

    override fun onCreate(db: SQLiteDatabase?) {
        val CREATE_TABLE = "CREATE TABLE $TABLE_NAME " +
                "($ID Integer PRIMARY KEY, $NAME TEXT, $AGE Integer, $WEIGHT Integer)"
        val res = db?.execSQL(CREATE_TABLE)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        val res = db?.execSQL("DROP TABLE IF EXISTS $TABLE_NAME")
        onCreate(db)
    }

    fun addStudent(student: Student): Boolean {
        val db = this.writableDatabase
        val values = ContentValues()
        values.put(NAME, student.name)
        values.put(AGE, student.age)
        values.put(WEIGHT, student.weight)
        val _success = db.insert(TABLE_NAME, null, values)
        db.close()
        Log.v("InsertedID", "$_success")
        return (Integer.parseInt("$_success") != -1)
    }

    fun readDB() : MutableList<Student> {
        var list : MutableList<Student> = ArrayList()
        val db = this.readableDatabase

        val query = "Select * from $TABLE_NAME"
        val result = db.rawQuery(query, null)

        if (result.moveToFirst()) {
            do {
                var stud = Student()
                stud.id = result.getString(0).toInt()
                stud.name = result.getString(1)
                stud.age = result.getString(2).toInt()
                stud.weight = result.getString(3).toInt()
                list.add(stud)
            } while (result.moveToNext())
        }
        list.sortBy { it.weight }
        result.close()
        db.close()
        return list
     }

    companion object {
        private val DB_NAME = "MyDB"
        private val DB_VERSIOM = 2;
        private val TABLE_NAME = "Students"
        private val ID = "id"
        private val NAME = "Name"
        private val AGE = "Age"
        private val WEIGHT = "Weight"
    }
}