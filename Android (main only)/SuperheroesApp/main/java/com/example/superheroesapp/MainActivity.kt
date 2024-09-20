package com.example.superheroesapp

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.aspectRatio
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.superheroesapp.ui.theme.SuperheroesAppTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            SuperheroesAppTheme {
                SuperheroesApp()
            }
        }
    }
}

@Composable
fun SingleSuperheroesCard(name: Int, description: Int, image: Int, modifier: Modifier = Modifier) {
    Surface(
        shape = RoundedCornerShape(20.dp),
//        contentColor = Color(0xFF89F8C7),
        modifier = modifier
            .fillMaxWidth()
            .height(150.dp)
            .padding(12.dp)
    ) {
        Row(
            modifier.background(Color(0xFF89F8C7))
        ) {
            Column(
                verticalArrangement = Arrangement.Center,
                modifier = modifier
                    .weight(2f)
                    .fillMaxHeight()
                    .padding(30.dp)
            ) {
                Text(
                    text = stringResource(id = name),
                    fontWeight = FontWeight.Bold,
                    fontSize = 20.sp
                )
                Text(text = stringResource(id = description))
            }
            Surface(
                shape = RoundedCornerShape(100.dp),
                modifier = modifier
                    .weight(1f)
                    .fillMaxSize()
                    .padding(12.dp)
            ) {
                Image(
                    painter = painterResource(id = image),
                    contentDescription = null,
                    contentScale = ContentScale.Crop,
                    modifier = modifier
                        .height(100.dp)
                        .aspectRatio(1f)
                        .fillMaxSize()
                )
            }
        }
    }
}

@Composable
fun SuperheroesApp() {
    LazyColumn(
        modifier = Modifier.padding(12.dp)
    ) {
        item {
            Text(
                text = "SUPERHEROES\nAPP",
                fontSize = 30.sp,
                textAlign = TextAlign.Center,
                fontFamily = FontFamily.Serif,
                lineHeight = 40.sp,
                color = Color(0xFF89F8C7),
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(20.dp)
                    .background(Color(0xFF005138))
            )
        }
        item { 
            SingleSuperheroesCard(
                name = R.string.hero1,
                description = R.string.description1,
                image = R.drawable.android_superhero1
            )
            SingleSuperheroesCard(
                name = R.string.hero2,
                description = R.string.description2,
                image = R.drawable.android_superhero2
            )
            SingleSuperheroesCard(
                name = R.string.hero3,
                description = R.string.description3,
                image = R.drawable.android_superhero3
            )
            SingleSuperheroesCard(
                name = R.string.hero4,
                description = R.string.description4,
                image = R.drawable.android_superhero4
            )
            SingleSuperheroesCard(
                name = R.string.hero5,
                description = R.string.description5,
                image = R.drawable.android_superhero5
            )
            SingleSuperheroesCard(
                name = R.string.hero6,
                description = R.string.description6,
                image = R.drawable.android_superhero6
            )
        }
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    SuperheroesAppTheme {
        SuperheroesApp()
    }
}