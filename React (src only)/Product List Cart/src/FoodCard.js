import { useAddAmount, useReduceAmount } from './AppState'
import cartIcon from './images/icon-add-to-cart.svg'
import decrementIcon from './images/icon-decrement-quantity.svg'
import incrementIcon from './images/icon-increment-quantity.svg'

export default function FoodCard({singleDessert}) {
    const handleAddAmount = useAddAmount()
    const handleReduceAmount = useReduceAmount()
    // console.log(dessertMenu)
    const idName = singleDessert["name"].replaceAll(" ", "-").toLowerCase()
    let imageDisplay = singleDessert["imageName"]
    if(window.innerWidth <= 400) {
        imageDisplay = singleDessert["imageMobile"]
    }
    let addToCart
    if(singleDessert["amount"] === 0) {
        addToCart = <button className='emptyCartButtonContainer' onClick={(e) => {handleAddAmount({
            ...singleDessert,
            amount: singleDessert["amount"]+1
        })}}>
            <img src={cartIcon} alt="cart icon" />
            <span> Add to Cart</span>
        </button>
    } else {
        // .operationSymbol and .operationSymbol:hover
        // maybe it's better to use button instead of div?
        addToCart = <div className='cartButtonContainer'>
            <button 
                onClick={(e) => {handleReduceAmount({
                    ...singleDessert,
                    amount: singleDessert["amount"]-1
                })}} className="operationSymbol"
            >
                <img src={decrementIcon} alt='decrement' />
            </button>
                <span className='amountFood'>{singleDessert["amount"]}</span>
            <button
                onClick={(e) => {handleAddAmount({
                    ...singleDessert,
                    amount: singleDessert["amount"]+1
                })}} className="operationSymbol"
            >
                <img src={incrementIcon} alt='increment' />
            </button>
        </div>
    }
    return(
        <section id={idName} className='foodCard'>
            <img src={imageDisplay} alt="name"/>
            <div className="addToCartButtonContainer">
                <div className='addToCartButton'>
                    {addToCart}
                </div>
            </div>
            <br/>
            <p id='dessertType'>{singleDessert["type"]}</p>
            <h3 id='dessertName'>{singleDessert["name"]}</h3>
            <h3 id='dessertPrice'>${singleDessert["price"].toFixed(2)}</h3>
        </section>
    )
}