import { useDataDessert } from "./AppState"

export default function OrderSummaryConfirmed() {
    const dataDessert = useDataDessert()
    
    const dessertSummary = dataDessert.map(singleDessert => {
        if(singleDessert["amount"] > 0) {
            return(
                <div className="singleItemConfirmed">
                    <div className="singleItemLeftContainer">
                        <img className="singleDessertImageConfirmed" src={singleDessert["imageThumbnail"]} />
                        <div className="singleDessertTextConfirmed">
                            <h5 className="singleDessertNameConfirmed">{singleDessert["name"]}</h5>
                            {/* <br/> */}
                            <p className="singleDessertNameAndPriceConfirmed">
                                <span className="singleDessertNameConfirmed">{singleDessert["amount"]}x</span>
                                <span className="singleDessertPriceConfirmed">@ ${singleDessert["price"]}</span>
                            </p>
                        </div>
                    </div>
                    <span className="singleDessertTotalPrice">${singleDessert["price"]}</span>
                </div>
            )
        }
    })

    return(
        <div>
            {dessertSummary}
        </div>
    )
}