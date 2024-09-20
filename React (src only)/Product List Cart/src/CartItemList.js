import CartItem from "./CartItem"
import emptyPlaceholder from "./images/illustration-empty-cart.svg"
import carbonNeutral from "./images/icon-carbon-neutral.svg"
import { useDataDessert, useHandleConfirmOrder, useTotalBill, useTotalInCart } from "./AppState"

export default function CartItemList() {
    const dataDessert = useDataDessert()
    const totalBill = useTotalBill()
    const totalInCart = useTotalInCart()
    const handleConfirmOrder = useHandleConfirmOrder()

    const itemList = dataDessert.map(singleData => {
        return(
            <CartItem
                key={singleData["name"]+"Item"}
                singleDessert={singleData}
            />
        )
    })

    if(totalBill > 0) {
        return(
            <article id="cartItemList">
                <h3 id="cartTitleNotEmpty" className="redColor">Your cart ( {totalInCart} )</h3>
                {itemList}
                <p id="orderTotal">
                    Order total <b>${totalBill.toFixed(2)}</b>
                </p>
                <div id="carbonNeutral">
                    <img src={carbonNeutral} alt="carbon neutral" />
                    <span>
                        This is a <b>carbon-neutral</b> delivery
                    </span>
                </div>
                <button onClick={() => handleConfirmOrder()} id="confirmButton">
                    Confirm Order
                </button>
            </article>
        )
    } else {
        // show that placeholder image
        return(
            <article id="cartItemList">
                <h3 id="cartTitleEmpty">Your cart ( {totalInCart} )</h3>
                <div id="emptyCartPlaceholder">
                    <img id="emptyCartImage" src={emptyPlaceholder} alt="empty placeholder"/>
                    <b id="emptyCartTextPlaceholder">You added item will appear here</b>
                </div>
            </article>
        )
    }
}