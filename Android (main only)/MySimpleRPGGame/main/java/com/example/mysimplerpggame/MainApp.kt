package com.example.mysimplerpggame

import androidx.compose.runtime.Composable
import androidx.navigation.NavController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController

@Composable
fun MainApp() {
    var navController = rememberNavController()
    NavHost(navController = navController, startDestination = "startpage") {
        composable("startpage") {
            StartPage(navController = navController)
        }
        composable("ingame") {
            InGame(navController = navController)
        }
    }
}