package com.example.clickbehaviourlemonade

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.clickbehaviourlemonade.ui.theme.ClickBehaviourLemonadeTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            ClickBehaviourLemonadeTheme {
                LemonadeProcess()
            }
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
fun LemonadeProcess(modifier: Modifier = Modifier) {
    var lemonProcess by remember{ mutableStateOf(1) }

    val imageResult = when(lemonProcess) {
        1 -> R.drawable.lemon_tree
        2 -> R.drawable.lemon_squeeze
        3 -> R.drawable.lemon_drink
        else -> R.drawable.lemon_restart
    }

    var squezee by remember{ mutableStateOf(0) }

    var textNow = when(lemonProcess) {
        1 -> "Tap the tree to select a lemon"
        2 -> "Keep tapping the lemon to squezee it "
        3 -> "Tap the lemonade to drink it"
        else -> "Tap the empty glass to start again"
    }

    val imageRender = painterResource(imageResult)
    Column(
        modifier.fillMaxSize()
    ) {
        Surface(
            color = Color.Green,
            modifier = modifier.fillMaxWidth()
        ) {
            Text(
                text = "Lemonade",
                textAlign = TextAlign.Center,
                modifier = modifier.padding(12.dp)
            )
        }
        Column(
            modifier.fillMaxSize(),
            verticalArrangement = Arrangement.Center,
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
//            Image(painter = imageRender, contentDescription = null)
            Surface(
//                contentColor = Color.Green
            ) {
                Button(onClick = {
                    if (lemonProcess >= 4)
                        lemonProcess = 1
                    else if (lemonProcess == 1) {
                        lemonProcess += 1
                        squezee = (2..5).random()
                    } else if (squezee > 0)
                        squezee -= 1
                    else
                        lemonProcess += 1
                }) {
                    Image(painter = imageRender, contentDescription = null)
                }
            }
            Spacer(modifier = modifier.height(16.dp))
            Text(
                text = textNow,
                fontSize = 20.sp
            )
        }
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    ClickBehaviourLemonadeTheme {
//        Greeting("Android")
        LemonadeProcess()
    }
}