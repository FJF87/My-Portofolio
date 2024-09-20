package com.example.mywhackamolegame

import android.media.MediaPlayer
import androidx.compose.foundation.Image
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.width
import androidx.compose.material.Button
import androidx.compose.material.RadioButton
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.rememberCoroutineScope
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.input.pointer.motionEventSpy
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import androidx.navigation.NavController
import kotlinx.coroutines.delay
import kotlin.random.Random

@Composable
fun InGame(navController: NavController, mediaPlayer: MediaPlayer) {
    val totalMole = 10
    var availableMole by remember {
        mutableStateOf(10)
    }
    var whackedMole by remember {
        mutableStateOf(0)
    }
    var activeMole by remember {
        mutableStateOf(0)
    }
    val moleList = mutableListOf<Int>(
            R.drawable.dirtready,
            R.drawable.dirtready,
            R.drawable.dirtready,
            R.drawable.dirtready
            )
//    var scope = rememberCoroutineScope()

//    while(availableMole > 0) {
    if (availableMole > 0) {
        activeMole = generateRandomMole(moleList)
        BoardGame (
            availableMole,
            whackedMole,
            activeMole,
            moleList,
            Modifier,
            { whackedMole++ },
            { availableMole-- }
        )
    } else {
        mediaPlayer.stop()
        mediaPlayer.prepare()
        EndGame(navController = navController)
    }
//        delay(2000)
//    }
}

@Composable
fun EndGame(navController: NavController) {
    Box {
        Image(
            painter = painterResource(id = R.drawable.backgroundingame2),
            contentDescription = "background 2",
            contentScale = ContentScale.Crop,
            modifier = Modifier.fillMaxSize()
        )
        Column(
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally,
            modifier = Modifier.fillMaxSize()
        ) {
            Text(text = "Congratulation!")
            Button(onClick = { navController.navigate("startpage") }) {
                Text(text = "To main page")
            }
        }
    }
}

fun generateRandomMole(moleList: MutableList<Int>): Int {
    var randomNumber = (0..3).random()
    moleList[randomNumber] = R.drawable.mergeddirtandmoleonly
    return randomNumber
}

@Composable
fun BoardGame(
    availableMole: Int,
    whackedMole: Int,
    activeMole: Int,
    moleList: MutableList<Int>,
    modifier: Modifier = Modifier,
    addPoint: () -> Int,
    substractRemainingMole: () -> Int
) {
    Box {
        Image(
            painter = painterResource(id = R.drawable.backgroundingame),
            contentDescription = "background image",
            contentScale = ContentScale.Crop,
            modifier = modifier.fillMaxSize()
        )
        Column(
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally,
            modifier = modifier.fillMaxSize()
        ) {
            Text(text = "Total mole left: $availableMole")
            Text(text = "Whacked mole: $whackedMole")
            Spacer(modifier = modifier.height(20.dp))
            Row(
                verticalAlignment = Alignment.CenterVertically,
                horizontalArrangement = Arrangement.Center
            ) {
                for (mole in moleList) {
                    if (mole == R.drawable.mergeddirtandmoleonly) {
                        Box(modifier = modifier.clickable {
                            /* Make it increase point on click */
                            addPoint()
                            substractRemainingMole()
                        }) {
                            Image(
                                painter = painterResource(id = mole),
                                contentDescription = "with mole",
                                modifier = modifier
                                    .width(100.dp)
                                    .height(100.dp)
                            )
                        }
                        //                    Button(onClick = { addPoint() }) {
                        //                        Text(text = "Click me")
                        //                    }
                    } else {
                        //                    Text(text = "$mole $activeMole \n")
                        Box {
                            Image(
                                painter = painterResource(id = mole),
                                contentDescription = "without mole",
                                modifier = modifier
                                    .width(100.dp)
                                    .height(100.dp)
                            )
                        }
                    }
                }
            }
        }
    }
}