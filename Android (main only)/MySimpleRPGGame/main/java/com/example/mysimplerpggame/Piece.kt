package com.example.mysimplerpggame

import android.util.MutableInt

open class Piece(
    var lives: Int,
    var damage: Int
) {
    fun takeDamage(damageTaken: Int) {
        lives -= damageTaken
    }
    fun giveDamage(): Int{
        return damage
    }
}