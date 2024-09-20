package com.example.mysimplerpggame

import android.widget.Space
import android.widget.Toast
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.width
import androidx.compose.material.Button
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.MutableState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import androidx.navigation.NavController

@Composable
fun InGame(navController: NavController) {
    var activeHero by rememberSaveable {
        mutableStateOf( Hero(25, 5,3) )
    }
    var level by rememberSaveable {
        mutableStateOf(0)
    }
    var activeEnemy by rememberSaveable {
        mutableStateOf(
            Enemy(0,0,"",0)
        )
    }

//    var tryHeroLives by remember {
//        mutableStateOf(25)
//    }
//    var tryEnemyLives by remember {
//        mutableStateOf(5)
//    }

    if (activeEnemy.lives > 0) {
        if(activeHero.lives < 0) {
            // game over
            GameOver(navController = navController)
        } else {
            // game still on
            GenerateBoard(
                activeHero = activeHero,
                activeEnemy = activeEnemy,
                level = level,
                useSpecialAttack = { activeHero.specialAttack-- },
                heroTakeDamage = { activeHero.lives-- },
                enemyTakeDamage = { activeEnemy.lives-- },
//                tryHeroLives = tryHeroLives,
//                tryEnemyLives = tryEnemyLives,
//                tryHeroDamaged = { tryHeroLives-- },
//                tryEnemyDamage = { tryEnemyLives-- }
            )
        }
    } else {
        if (level < 4) {
            level++
            val getEnemyLivesData = enemyLives.values
            val getEnemyDamageData = enemyDamage.values
            activeEnemy.lives = getEnemyLivesData.elementAt((level - 1))
            activeEnemy.damage = getEnemyDamageData.elementAt((level - 1))
            activeEnemy.name = enemyName.elementAt((level - 1))
            activeEnemy.picture = enemyPicture.elementAt((level - 1))
            // want to refill the hero lives to full?
            // how about the bonus?
        } else {
            // show "you win!"
            EndGame(navController = navController)
        }
    }
}

@Composable
fun GameOver(navController: NavController) {
    Text(text = "You lose!")
//    Button(onClick = {  }) {
//        Text(text = "Continue")
//    }
    Button(onClick = { navController.navigate("startpage") }) {
        Text(text = "Give up")
    }
}

@Composable
fun EndGame(navController: NavController, modifier: Modifier = Modifier) {
    Box {
        Column(
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally,
            modifier = modifier.fillMaxWidth()
        ) {
            Text(text = "You Won!")
            Button(onClick = { navController.navigate("startpage") }) {
                Text(text = "Back to main page")
            }
        }
    }
}

@Composable
fun GenerateBoard(
    activeHero: Hero,
    activeEnemy: Enemy,
    level: Int,
    useSpecialAttack: () -> Int,
    heroTakeDamage: () -> Int,
    enemyTakeDamage: () -> Int,
//    tryHeroLives: Int,
//    tryEnemyLives: Int,
//    tryHeroDamaged: () -> Int,
//    tryEnemyDamage: () -> Int,
    modifier: Modifier = Modifier
) {
//    var enemyDice = generateDiceNumber()
//    var heroDice = 0
    Box {
        Column(
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally,
            modifier = modifier.fillMaxSize()
        ) {
            Row( // this is the information on top
                verticalAlignment = Alignment.CenterVertically,
                horizontalArrangement = Arrangement.Center,
                modifier = modifier.fillMaxWidth()
            ) {
                Column {
                    Text(text = "Your Hero")
//                    Text(text = "Try hero lives: $tryHeroLives")
                    Text(text = "lives: ${activeHero.lives}")
                    Text(text = "power: ${activeHero.damage}")
                    Text(text = "special attack left: ${activeHero.specialAttack}")
                }
                Text(text = "level: $level")
                Column {
                    Text(text = "Enemy")
                    Text(text = activeEnemy.name)
//                    Text(text = "Try enemy lives: $tryEnemyLives")
                    Text(text = "lives: ${activeEnemy.lives}")
                    Text(text = "power: ${activeEnemy.damage}")
                }
            }
            Spacer(modifier = modifier.height(20.dp))
            Image(
                painter = painterResource(id = activeEnemy.picture),
                contentDescription = "Enemy"
            )
            Spacer(modifier = modifier.height(20.dp))
            Row {
                Button(onClick = {
//                    tryHeroDamaged()
//                    tryEnemyDamage()
                    heroTakeDamage()
                    enemyTakeDamage()
//                    handleAttack(activeHero, activeEnemy,false)
                }) {
                    Text(text = "Roll the dice\n(Normal Attack)")
                }
                Spacer(modifier = modifier.width(10.dp))
                Button(onClick = {
                    useSpecialAttack()
                    handleAttack(activeHero,activeEnemy,true)
//                    Toast.makeText(this,
//                        "You get ${result.elementAt(0)} enemy got ${result.elementAt(1)}\n" +
//                                "You take ${result.elementAt(2)} enemy take ${result.elementAt(3)}",
//                        Toast.LENGTH_SHORT).show()
                }) {
                    Text(text = "Special Attack\n(Double The Result of your dice)")
                }
            }
        }
    }
}

fun handleAttack(activeHero: Hero, activeEnemy: Enemy, useSpecialAttack: Boolean): List<Int> {
    var damageToHero = 0
    var damageToEnemy = 0

    var heroDice = when(useSpecialAttack) {
        true -> generateDiceNumber() * 2
        else -> generateDiceNumber()
    }
    var enemyDice = generateDiceNumber()

    if(heroDice < enemyDice) {
        // hero take damage
        damageToHero = enemyDice - heroDice
        activeHero.takeDamage(damageToHero)
    } else if(heroDice > enemyDice) {
        // enemy take damage
        damageToEnemy = heroDice - enemyDice
        activeEnemy.takeDamage(damageToEnemy)
    }

    return listOf(heroDice, enemyDice, damageToHero, damageToEnemy)
}

fun generateDiceNumber(): Int {
    var randomNumber = (1..6).random()
    return randomNumber
}