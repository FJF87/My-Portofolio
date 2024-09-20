package com.example.cuteanimalgallery

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.getValue
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.cuteanimalgallery.ui.theme.CuteAnimalGalleryTheme
import org.intellij.lang.annotations.JdkConstants.HorizontalAlignment

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            CuteAnimalGalleryTheme {
                AnimalGallery()
            }
        }
    }
}

@Composable
fun AnimalGallery(modifier: Modifier = Modifier) {
    var number by remember { mutableStateOf(1) }

    var imageNow = when(number) {
        1 -> R.drawable.cat
        2 -> R.drawable.fox
        3 -> R.drawable.duck
        4 -> R.drawable.racoon
        5 -> R.drawable.artic
        6 -> R.drawable.hamster
        7 -> R.drawable.little_bird
        else -> R.drawable.puppy
    }
    
    var imageDescription = when(number) {
        1 -> "cat"
        2 -> "fox"
        3 -> "duck"
        4 -> "racoon"
        5 -> "artic"
        6 -> "hamster"
        7 -> "little_bird"
        else -> "puppy"
    }

    Column (
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally,
        modifier = modifier
            .fillMaxSize()
    ) {
        Surface(
//            contentColor = Color.Green,
            modifier = modifier.fillMaxWidth()
        ) {
            Text(
                text = "Animal Gallery",
                fontSize = 30.sp,
                fontFamily = FontFamily.Serif,
                fontWeight = FontWeight.Bold,
                textAlign = TextAlign.Center
            )
        }
        Spacer(modifier = modifier.height(50.dp))
        Image(
            painter = painterResource(id = imageNow),
            contentDescription = imageDescription,
            contentScale = ContentScale.Fit,
            modifier = modifier.height(150.dp)
        )
        Spacer(modifier = modifier.height(50.dp))
        Text(
            text = imageDescription,
            fontSize = 20.sp
        )
        Spacer(modifier = modifier.height(50.dp))
        Row(
            horizontalArrangement = Arrangement.SpaceAround,
            verticalAlignment = Alignment.CenterVertically,
            modifier = modifier.fillMaxWidth()
        ) {
            Button(onClick = {
                if (number <= 1) {
                    number = 8
                } else {
                    number--
                }
            }) {
                Text(text = "Prev")
            }
            Button(onClick = {
                if (number >= 8) {
                    number = 1
                } else {
                    number++
                }
            }) {
                Text(text = "Next")
            }
        }
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    CuteAnimalGalleryTheme {
        AnimalGallery()
    }
}