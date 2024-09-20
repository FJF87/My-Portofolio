package com.example.mywhackamolegame

import android.media.MediaPlayer
import androidx.compose.runtime.Composable
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController

@Composable
fun MainApp(mediaPlayer: MediaPlayer) {
    var navController = rememberNavController()
    NavHost(navController = navController, startDestination = "startpage") {
        composable("startpage") {
            StartPage(navController = navController, mediaPlayer)
        }
        composable("ingame") {
            InGame(navController = navController, mediaPlayer)
        }
    }
}