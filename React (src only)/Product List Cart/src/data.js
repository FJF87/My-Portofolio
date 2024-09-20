import brownie from './images/image-brownie-desktop.jpg'
import baklava from './images/image-baklava-desktop.jpg'
import cake from './images/image-cake-desktop.jpg'
import cremeBrulee from './images/image-creme-brulee-desktop.jpg'
import macaron from './images/image-macaron-desktop.jpg'
import meringue from './images/image-meringue-desktop.jpg'
import pannaCotta from './images/image-panna-cotta-desktop.jpg'
import tiramisu from './images/image-tiramisu-desktop.jpg'
import waffle from './images/image-waffle-desktop.jpg'

import brownieThumbnail from './images/image-brownie-thumbnail.jpg'
import baklavaThumbnail from './images/image-baklava-thumbnail.jpg'
import cakeThumbnail from './images/image-cake-thumbnail.jpg'
import cremeBruleeThumbnail from './images/image-creme-brulee-thumbnail.jpg'
import macaronThumbnail from './images/image-macaron-thumbnail.jpg'
import meringueThumbnail from './images/image-meringue-thumbnail.jpg'
import pannaCottaThumbnail from './images/image-panna-cotta-thumbnail.jpg'
import tiramisuThumbnail from './images/image-tiramisu-thumbnail.jpg'
import waffleThumbnail from './images/image-waffle-thumbnail.jpg'

import brownieMobile from './images/image-brownie-mobile.jpg'
import baklavaMobile from './images/image-baklava-mobile.jpg'
import cakeMobile from './images/image-cake-mobile.jpg'
import cremeBruleeMobile from './images/image-creme-brulee-mobile.jpg'
import macaronMobile from './images/image-macaron-mobile.jpg'
import meringueMobile from './images/image-meringue-mobile.jpg'
import pannaCottaMobile from './images/image-panna-cotta-mobile.jpg'
import tiramisuMobile from './images/image-tiramisu-mobile.jpg'
import waffleMobile from './images/image-waffle-mobile.jpg'


// export const IMAGEPREFIX = "./images/image-"
// export const IMAGEPOSTFIX = {
//     desktop: "-desktop",
//     mobile: "-mobile",
//     tablet: "-tablet",
//     thumbnail: "-thumbnail"
// }
// export const IMAGEEXTENSION = ".jpg"

export const dessertMenus = [
    {
        name: "Waffle with Berries",
        type: "Waffle",
        price: 6.50,
        imageName: waffle,
        imageThumbnail: waffleThumbnail,
        imageMobile: waffleMobile,
        amount: 0
    },
    {
        name: "Vanilla Bean Crème Brûlée",
        type: "Crème Brûlée",
        price: 7.00,
        imageName: cremeBrulee,
        imageThumbnail: cremeBruleeThumbnail,
        imageMobile: cremeBruleeMobile,
        amount: 0
    },
    {
        name: "Macaron Mix of Five",
        type: "Macaron",
        price: 8.00,
        imageName: macaron,
        imageThumbnail: macaronThumbnail,
        imageMobile: macaronMobile,
        amount: 0
    },
    {
        name: "Classic Tiramisu",
        type: "Tiramisu",
        price: 5.50,
        imageName: tiramisu,
        imageThumbnail: tiramisuThumbnail,
        imageMobile: tiramisuMobile,
        amount: 0
    },
    {
        name: "Pistachio Baklava",
        type: "Baklava",
        price: 4.00,
        imageName: baklava,
        imageThumbnail: baklavaThumbnail,
        imageMobile: baklavaMobile,
        amount: 0
    },
    {
        name: "Lemon Meringue Pie",
        type: "Pie",
        price: 5.00,
        imageName: meringue,
        imageThumbnail: meringueThumbnail,
        imageMobile: meringueMobile,
        amount: 0
    },
    {
        name: "Red Velvet Cake",
        type: "Cake",
        price: 4.50,
        imageName: cake,
        imageThumbnail: cakeThumbnail,
        imageMobile: cakeMobile,
        amount: 0
    },
    {
        name: "Salted Caramel Brownie",
        type: "Brownie",
        price: 4.50,
        imageName: brownie,
        imageThumbnail: brownieThumbnail,
        imageMobile: brownieMobile,
        amount: 0
    },
    {
        name: "Vanilla Panna Cotta",
        type: "Panna Cotta",
        price: 6.50,
        imageName: pannaCotta,
        imageThumbnail: pannaCottaThumbnail,
        imageMobile: pannaCottaMobile,
        amount: 0
    }
]