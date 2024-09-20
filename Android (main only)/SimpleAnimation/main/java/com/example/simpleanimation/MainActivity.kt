package com.example.simpleanimation

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.animation.core.LinearOutSlowInEasing
import androidx.compose.animation.core.animateDpAsState
import androidx.compose.animation.core.animateIntAsState
import androidx.compose.animation.core.tween
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.material3.Button
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.simpleanimation.ui.theme.SimpleAnimationTheme
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.delay
import kotlinx.coroutines.isActive

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
//            AnimateStickman() -- DON'T USE THIS ONE!
//            AnimateBox()
//            AnimatePicture()
        }
    }
}

@Composable
fun AnimatePicture() {
    var currentPicture by remember {
        mutableStateOf(R.drawable.stickman1)
    }
    LaunchedEffect(key1 = currentPicture) {
        while(isActive) {
            delay(1000)
            if (currentPicture == R.drawable.stickman1) {
                currentPicture = R.drawable.stickman2
            } else {
                currentPicture = R.drawable.stickman1
            }
        }
    }
    Image(
        painter = painterResource(id = currentPicture),
        contentDescription = "stickman",
        modifier = Modifier.height(500.dp).width(500.dp)
    )
}

@Composable
fun AnimateBox() {
    var currentBoxSize by remember {
        mutableStateOf(150.dp)
    }
    val animateBoxSize by animateDpAsState(
        targetValue = currentBoxSize,
        tween(
            durationMillis = 1000,
            delayMillis = 1000,
            easing = LinearOutSlowInEasing
        )
    )
    Box(
        modifier = Modifier
            .width(animateBoxSize)
            .height(animateBoxSize)
            .background(Color.Black)
    ) {
        Button(onClick = { currentBoxSize += 50.dp }, modifier = Modifier.fillMaxSize()) {
            Text(text = "add box size")
        }
    }
}

// DON'T USE THIS ONE!
//@Composable
//fun AnimateStickman() {
//    var activePicture by remember {
//        mutableStateOf(R.drawable.stickman1)
//    }
//    val pictureAnimation by animateIntAsState(
//        targetValue = activePicture,
//        tween(
//            durationMillis = 2000,
//            delayMillis = 2000
//        )
//    )
//    Box(modifier = Modifier.fillMaxSize()) {
//        Image(painter = painterResource(id = pictureAnimation), contentDescription = "stickman")
//        Button(onClick = {
//
//        }) {
//            Text(text = "animate")
//        }
//    }
//}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    SimpleAnimationTheme {

    }
}