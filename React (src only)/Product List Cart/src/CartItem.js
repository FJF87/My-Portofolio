import { useHandleResetAmount } from "./AppState"
import removeIcon from "./images/icon-remove-item.svg"

export default function CartItem({singleDessert}){
    const handleResetAmount = useHandleResetAmount()
    
    const totalPricePerItem = singleDessert["price"] * singleDessert["amount"]
    let renderData = <></>
    if(singleDessert["amount"] > 0) {
        renderData = <>
                    <div id="itemCartContainer">
                        <div id="itemOrder">
                            <b id="itemOrderDessertName">{singleDessert["name"]}</b>
                            <span id="itemOrderDessertPrice">
                                <b className="redColor">{singleDessert["amount"]}x</b>
                                <span className="greyColor">@${singleDessert["price"].toFixed(2)}</span>
                                <span className="darkGreyColor">${totalPricePerItem.toFixed(2)}</span>
                            </span>
                        </div>
                            <div onClick={e => {
                                                handleResetAmount({
                                                    ...singleDessert,
                                                    amount: 0
                                                })
                                            }}
                                    id="removeButton"
                            >
                                <img src={removeIcon} alt="remove icon" />
                            </div>
                    </div>
                </>
    }
    
    return renderData
}