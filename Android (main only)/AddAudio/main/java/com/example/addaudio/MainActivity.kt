package com.example.addaudio

import android.content.Context
import android.media.MediaPlayer
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material.icons.Icons
import androidx.compose.material3.Button
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.tooling.preview.Preview
import com.example.addaudio.ui.theme.AddAudioTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
//            AudioPlayer()
            AudioPlayerFromAndroidDeveloper(context = this)
        }
    }
}

//@Composable
//fun Greeting(name: String, modifier: Modifier = Modifier) {
//    Text(
//        text = "Hello $name!",
//        modifier = modifier
//    )
//}

@Composable
fun AudioPlayer(modifier: Modifier = Modifier) {
    var mediaPlayer = MediaPlayer.create(LocalContext.current, R.raw.mario)

    Column(
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally,
        modifier = modifier.fillMaxSize()
    ) {
        Row {
            Button(onClick = {
                mediaPlayer.seekTo(0)
                mediaPlayer.start()
            }) {
                Text(text = "play")
            }
            Button(onClick = {
                mediaPlayer.pause()
            }) {
                Text(text = "pause")
            }
            Button(onClick = {
                mediaPlayer.start()
            }) {
                Text(text = "continue")
            }
        }
    }
}

@Composable
fun AudioPlayerFromAndroidDeveloper(context: Context) {
    var mediaPlayer = MediaPlayer.create(context, R.raw.mario)
    mediaPlayer.start() // no need to call prepare(); create() does that for you
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    AddAudioTheme {
//        Greeting("Android")
    }
}