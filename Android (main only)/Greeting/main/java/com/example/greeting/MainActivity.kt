package com.example.greeting

import android.os.Bundle
import android.view.SurfaceControl
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import com.example.greeting.ui.theme.GreetingTheme
import androidx.compose.ui.unit.dp
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Surface
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.sp

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            Box(modifier = Modifier){
                GreetingTheme {
                    Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                        Greeting(
                            name = "Android",
                            modifier = Modifier.padding(innerPadding)
                        )
                    }
                }
            }
        }
    }
}

@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Surface(color = Color.Blue) {
        Text(
            text = "Hi $name!",
            modifier = modifier.padding(20.dp)
        )
    }
}

@Composable
fun BackgroundImage(message: String, modifier: Modifier = Modifier) {
    val image = painterResource(R.drawable.aplace)
    Box{
        Image(
            painter = image,
            contentDescription = null
        )
        Column(
            verticalArrangement = Arrangement.Center,
            modifier = modifier
        ) {
            Surface(color = Color.Blue) {
                Text(
                    text = message,
                    modifier = modifier.padding(20.dp),
                    color = Color.Cyan,
                    fontSize = 20.sp
                )
            }
        }
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    GreetingTheme {
//        Greeting("Android")
        BackgroundImage(message = "hello there")
    }
}

//@Preview(showBackground = true)
//@Composable
//fun BackgroundImagePreview() {
//    BackgroundImageTheme {
//        BackgroundImage(message = "background image")
//    }
//}