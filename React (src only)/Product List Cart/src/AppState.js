import { createContext, useContext, useState, useEffect } from "react"
import { dessertMenus } from "./data"


const DataDessertGlobal = createContext()
const TotalBillGlobal = createContext()
const TotalInCartGlobal = createContext()
const ShowOrderSummaryGlobal = createContext()

export function useDataDessert() {
    return useContext(DataDessertGlobal)
}

export function useTotalBill() {
    return useContext(TotalBillGlobal)
}

export function useTotalInCart() {
    return useContext(TotalInCartGlobal)
}

export function useShowOrderSummary() {
    return useContext(ShowOrderSummaryGlobal)
}


const AddAmountGlobal = createContext()
const ReduceAmountGlobal = createContext()
const HandleResetAmountGlobal = createContext()
const HandleConfirmOrderGlobal = createContext()
const HandleResetDataGlobal = createContext()

export function useAddAmount() {
    return useContext(AddAmountGlobal)
}

export function useReduceAmount() {
    return useContext(ReduceAmountGlobal)
}

export function useHandleResetAmount() {
    return useContext(HandleResetAmountGlobal)
}

export function useHandleConfirmOrder() {
    return useContext(HandleConfirmOrderGlobal)
}

export function useHandleResetData() {
    return useContext(HandleResetDataGlobal)
}

export default function AppState({children}) {
    const [dataDessert, setDataDessert] = useState(dessertMenus)
    const [totalBill, setTotalBill] = useState(0)
    const [totalInCart, setTotalInCart] = useState(0)
    const [showOrderSummary, setShowOrderSummary] = useState(false)

    function addAmount(dataDessertToBeUpdated) {
        setDataDessert(dataDessert.map(singleData => {
            if(singleData["name"] === dataDessertToBeUpdated["name"]) {
            return dataDessertToBeUpdated
            } else {
            return singleData
            }
        }))
    }
    
    function reduceAmount(dataDessertToBeUpdated) {
        setDataDessert(dataDessert.map(singleData => {
            if(singleData["name"] === dataDessertToBeUpdated["name"]) {
            return dataDessertToBeUpdated
            } else {
            return singleData
            }
        }))
    }
    
    function handleResetAmount(dataDessertToBeUpdated) {
        setDataDessert(dataDessert.map(singleData => {
            if(singleData["name"] === dataDessertToBeUpdated["name"]) {
            return dataDessertToBeUpdated
            } else {
            return singleData
            }
        }))
    }
    
    function handleConfirmOrder() {
        setShowOrderSummary(!showOrderSummary)
    }
    
    function handleResetData() {
        setTotalBill(0)
        setTotalInCart(0)
        setShowOrderSummary(false)
        setDataDessert(dessertMenus)
    }
    
    useEffect(() => {
        const totalBill = dataDessert.reduce((prevVal, currDesert) => {
            return prevVal + currDesert["amount"] * currDesert["price"]
        }, 0)
        const totalInCart = dataDessert.reduce((prevVal, currVal) => {
            return prevVal + currVal["amount"]
        }, 0)
        setTotalBill(totalBill)
        setTotalInCart(totalInCart)
    }, [dataDessert])

    return(
        <DataDessertGlobal.Provider value={dataDessert}>
            <TotalBillGlobal.Provider value={totalBill}>
                <TotalInCartGlobal.Provider value={totalInCart}>
                    <ShowOrderSummaryGlobal.Provider value={showOrderSummary}>
                        <AddAmountGlobal.Provider value={addAmount}>
                            <ReduceAmountGlobal.Provider value={reduceAmount}>
                                <HandleResetAmountGlobal.Provider value={handleResetAmount}>
                                    <HandleConfirmOrderGlobal.Provider value={handleConfirmOrder}>
                                        <HandleResetDataGlobal.Provider value={handleResetData}>
                                            {children}
                                        </HandleResetDataGlobal.Provider>
                                    </HandleConfirmOrderGlobal.Provider>
                                </HandleResetAmountGlobal.Provider>
                            </ReduceAmountGlobal.Provider>
                        </AddAmountGlobal.Provider>
                    </ShowOrderSummaryGlobal.Provider>
                </TotalInCartGlobal.Provider>
            </TotalBillGlobal.Provider>
        </DataDessertGlobal.Provider>
    )
}