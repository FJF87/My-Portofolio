package com.example.mysimplerpggame

class Hero(lives: Int, damage: Int, var specialAttack: Int): Piece(lives, damage) {
    fun addLives(livesToBeAdded: Int) {
        lives += livesToBeAdded
    }
    fun addDamage(damageToBeAdded: Int) {
        damage += damageToBeAdded
    }
    fun addSpecialAttack(specialAttackToBeAdded: Int) {
        specialAttack += specialAttackToBeAdded
    }
//    fun giveSpecialAttack(): Int {
//        specialAttack--
//        return (damage*2)
//    }
}