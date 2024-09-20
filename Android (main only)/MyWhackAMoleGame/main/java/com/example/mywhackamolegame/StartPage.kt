package com.example.mywhackamolegame

import android.media.MediaPlayer
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController

@Composable
fun StartPage(navController: NavController, mediaPlayer: MediaPlayer, modifier: Modifier = Modifier) {
    Box {
        Image(
            painter = painterResource(id = R.drawable.backgroundingame2),
            contentDescription = "background2",
            contentScale = ContentScale.Crop,
            modifier = modifier.fillMaxSize()
        )
        Column(
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally,
            modifier = modifier.fillMaxSize()
        ) {
            Image(
                painter = painterResource(id = R.drawable.start),
                contentDescription = "start image"
            )
            Spacer(modifier = modifier.height(20.dp))
            Text(text = "Whack A Mole!", fontSize = 30.sp)
            //        Text(text = "The highest score is ")
            Spacer(modifier = modifier.height(20.dp))
            Button(onClick = {
                mediaPlayer.start()
                navController.navigate("ingame")
            }) {
                Text(text = "Start")
            }
        }
    }
}