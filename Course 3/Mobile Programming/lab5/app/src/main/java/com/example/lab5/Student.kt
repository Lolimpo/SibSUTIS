package com.example.lab5

class Student
{
    var age: Int = 0
    var name: String = ""
    var id: Int = 0
    var weight: Int = 0

    constructor(name: String, age: Int, weight: Int) {
        this.age = age
        this.name = name
        this.weight = weight
    }

    constructor()
}