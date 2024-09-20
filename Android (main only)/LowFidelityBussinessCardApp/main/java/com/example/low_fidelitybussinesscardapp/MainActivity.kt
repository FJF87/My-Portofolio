package com.example.low_fidelitybussinesscardapp

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.tooling.preview.Preview
import com.example.low_fidelitybussinesscardapp.ui.theme.LowFidelityBussinessCardAppTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            LowFidelityBussinessCardAppTheme {
                Surface {
                    BussinesCard()
                }
            }
        }
    }
}

@Composable
fun MainInformation(
    fullname: String,
    title: String
) {
//    val image = painterResource(R.drawable)
    Column {
//        Image(painter = image, contentDescription = null)
        Text(text = fullname)
        Text(text = title)
    }
}

@Composable
fun AdditionalInformation(
    phonenumber: String,
    socialmedia: String,
    email: String
) {
    val phoneNumberIcon = painterResource(R.drawable.phone_icon)
    val shareIcon = painterResource(R.drawable.share_icon)
    val emailIcon = painterResource(R.drawable.email_icon)
    Column {
        Row {
            Image(painter = phoneNumberIcon, contentDescription = null)
            Text(text = phonenumber)
        }
        Row {
            Image(painter = shareIcon, contentDescription = null)
            Text(text = socialmedia)
        }
        Row {
            Image(painter = emailIcon, contentDescription = null)
            Text(text = email)
        }
    }
}

@Composable
fun BussinesCard() {
    Column {
        MainInformation(
            fullname = "Name",
            title = "Title"
        )
//        Spacer(modifier = )
        AdditionalInformation(
            phonenumber = "0999878766554",
            socialmedia = "@twitter",
            email = "name@gmail.com"
        )
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    LowFidelityBussinessCardAppTheme {
        BussinesCard()
    }
}