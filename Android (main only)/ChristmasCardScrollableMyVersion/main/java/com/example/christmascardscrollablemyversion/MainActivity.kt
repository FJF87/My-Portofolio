package com.example.christmascardscrollablemyversion

import android.media.Image
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.ScrollState
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.aspectRatio
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.verticalScroll
import androidx.compose.material3.Card
import androidx.compose.material3.CardColors
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.ImageBitmapConfig
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.semantics.Role.Companion.Image
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.christmascardscrollablemyversion.ui.theme.ChristmasCardScrollableMyVersionTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            ChristmasCardScrollableMyVersionTheme {
                ChristmasCardApp()
//                TryScrollable()
            }
        }
    }
}

@Composable
fun ChristmasCard(title: String, imageID: Int, modifier: Modifier = Modifier) {
    Card(
        modifier = modifier
            .padding(20.dp)
    ) {
//        Image(painter = imageID, contentDescription = title)
        Image(
            painter = painterResource(id = imageID),
            contentDescription = title,
            contentScale = ContentScale.Fit,
            modifier = modifier
                .fillMaxWidth()
                .aspectRatio(1.5f)
        )
        Text(
            text = title,
            textAlign = TextAlign.Center,
            fontSize = 20.sp,
            modifier = modifier
                .fillMaxSize()
        )
    }
}

// Cannot be scrolled
@Composable
fun ChristmasCardApp(modifier: Modifier = Modifier) {
//    LazyColumn(
//        userScrollEnabled = true,
//        modifier = modifier
//    ) {
    LazyColumn(
//        contentPadding = PaddingValues(vertical = 20.dp),
        modifier = modifier
            .padding(20.dp)
            .background(Color.Green)
//            .fillMaxSize()
//            .verticalScroll(ScrollState())
    ) {
        item {
            Text(
                text = "Christmas Card App\nMerry Christmas!",
                textAlign = TextAlign.Center,
                fontWeight = FontWeight.Bold,
                fontSize = 25.sp,
                fontFamily = FontFamily.Monospace,
                color = Color.Red,
                modifier = modifier
                    .fillParentMaxWidth()
                    .padding(20.dp)
            )
        }
        item {
            ChristmasCard(title = "Christmas Tree", imageID = R.drawable.christmas_tree)
        }
        item {
            ChristmasCard(title = "Rudolf", imageID = R.drawable.rudolf)
        }
        item {
            ChristmasCard(title = "Santa", imageID = R.drawable.santa)
        }
        item {
            ChristmasCard(title = "Christmas Cookies", imageID = R.drawable.cookies)
        }
        item {
            ChristmasCard(title = "Christmas Decoration", imageID = R.drawable.christmas_decoration)
        }
        item {
            ChristmasCard(title = "Snowman", imageID = R.drawable.snowman)
        }
    }
}

@Composable
fun ShowNumber(number: Int) {
    Text(text = "Text number $number")
}

//@Composable
//fun TryScrollable(modifier: Modifier = Modifier) {
//    Column(
//        verticalArrangement = Arrangement.SpaceAround,
//        horizontalAlignment = Alignment.CenterHorizontally,
//        modifier = modifier.fillMaxSize()
//    ) {
//        LazyColumn {
//            items((1..50).toList()) { number ->
//                //            Text(text = "Text number $number")
//                ShowNumber(number)
//            }
//        }
//    }
//}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    ChristmasCardScrollableMyVersionTheme {
        ChristmasCardApp()
//        TryScrollable()
    }
}