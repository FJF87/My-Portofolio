import { useHandleResetData, useShowOrderSummary, useTotalBill } from './AppState'
import confirmedIcon from './images/icon-order-confirmed.svg'
import OrderSummaryConfirmed from './OrderSummaryConfirmed'

export default function OrderConfirmation() {
    const totalBill = useTotalBill()
    const showOrderSummary = useShowOrderSummary()
    const handleResetData = useHandleResetData()

    const contentToBeShown = <>
                                <div id='confirmedContainer'>
                                    <div id='innerConfirmedContainer'>
                                        <img id='confirmedIcon' src={confirmedIcon} alt='confirmed icon' />
                                        <h2 id='confirmedTitle'>Order Confirmed</h2>
                                        <p id='confirmedDescription'>We hope you enjoy your food</p>
                                        <div id='orderSummaryContainer'>
                                            <OrderSummaryConfirmed/>
                                            <div id='orderTotalContainerConfirmed'>
                                                <span id='orderTotalText'>Order Total</span>
                                                <span id='orderTotalBill'>${totalBill}</span>
                                            </div>
                                        </div>
                                        <button onClick={() => handleResetData()} id='resetButton'>Start new order</button>
                                    </div>
                                </div>
                            </>
    
    if(showOrderSummary) {
        return(
            <section id='customAlertConfirmed'>
                {contentToBeShown}
            </section>
        )
    } else {
        return<></>
    }
}