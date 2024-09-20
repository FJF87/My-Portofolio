package com.example.mysimplerpggame

class Enemy(
    lives: Int,
    damage: Int,
    var name: String,
    var picture: Int
): Piece(lives, damage)