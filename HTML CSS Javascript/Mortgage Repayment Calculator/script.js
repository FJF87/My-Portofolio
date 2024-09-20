document.addEventListener("DOMContentLoaded", () => {
    const getMortgageAmount = document.getElementById("mortgageAmount")
    getMortgageAmount.addEventListener("focus", () => {
        getMortgageAmount.classList.remove("inputAlert")
        getMortgageAmount.classList.add("inputIdle")
        document.getElementById("dollarSign").classList.remove("alertBackground")
        document.getElementById("dollarSign").classList.remove("stale100Background")
        document.getElementById("dollarSign").classList.add("limeBackground")
    })
    getMortgageAmount.addEventListener("blur", () => {
        document.getElementById("dollarSign").classList.remove("limeBackground")
        document.getElementById("dollarSign").classList.add("stale100Background")
    })

    const getMortgageTerm = document.getElementById("mortgageTerm")
    getMortgageTerm.addEventListener("focus", () => {
        getMortgageTerm.classList.remove("inputAlert")
        getMortgageTerm.classList.add("inputIdle")
        document.getElementById("years").classList.remove("alertBackground")
        document.getElementById("years").classList.remove("stale100Background")
        document.getElementById("years").classList.add("limeBackground")
    })
    getMortgageTerm.addEventListener("blur", () => {
        document.getElementById("years").classList.remove("limeBackground")
        document.getElementById("years").classList.add("stale100Background")
    })

    const getInterestRate = document.getElementById("interestRate")
    getInterestRate.addEventListener("focus", () => {
        getInterestRate.classList.remove("inputAlert")
        getInterestRate.classList.add("inputIdle")
        document.getElementById("percentSymbol").classList.remove("alertBackground")
        document.getElementById("percentSymbol").classList.remove("stale100Background")
        document.getElementById("percentSymbol").classList.add("limeBackground")
    })
    getInterestRate.addEventListener("blur", () => {
        document.getElementById("percentSymbol").classList.remove("limeBackground")
        document.getElementById("percentSymbol").classList.add("stale100Background")
    })

    var selectedRadioPrev = null;
    // you're taking the wrong element. you should get the div, not the radio button
    const getAllMortgageType = document.querySelectorAll("#radioContainer")
    getAllMortgageType.forEach(getMortgageType => {
        getMortgageType.addEventListener("change", () => {
            if(selectedRadioPrev != getMortgageType) {
                if(selectedRadioPrev != null) {
                    // if there is something selected before, update it
                    selectedRadioPrev.classList.remove("radioOutlineSelected")
                    selectedRadioPrev.classList.add("radioOutlineUnselected")
                }
                getMortgageType.classList.remove("radioOutlineUnselected")
                getMortgageType.classList.add("radioOutlineSelected")
                selectedRadioPrev = getMortgageType
            }
        })
    })

    const getButton = document.getElementById("calculateButton")
    getButton.addEventListener("click", () => {
        const userMortgageAmount = Number(document.getElementById("mortgageAmount").value)
        const userMortgageTerm = Number(document.getElementById("mortgageTerm").value)
        const userInterestRate = Number(document.getElementById("interestRate").value)
        const userMortgageType = document.querySelector("input[name='mortgageType']:checked")

        if(
            userMortgageAmount != 0 &&
            userMortgageTerm != 0 &&
            userInterestRate != 0 &&
            userMortgageType != null
        ) {
            const userMortgageType = document.querySelector("input[name='mortgageType']:checked").value

            const totalInterest = userMortgageAmount * (userInterestRate/100)
            const totalRepay = totalInterest + userMortgageAmount
            const totalInterestPerMonth = totalInterest/(userMortgageTerm*12)
            const totalRepayPerMonth = totalRepay/(userMortgageTerm*12)

            var montlyShown = 0
            var totalShown = 0

            if(userMortgageType == "repayment") {
                montlyShown = totalRepayPerMonth
                totalShown = totalRepay
            } else if(userMortgageType == "interestOnly") {
                montlyShown = totalInterestPerMonth
                totalShown = totalInterest
            }

            montlyShown = Math.round(montlyShown * 100) / 100
            totalShown = Math.round(totalShown * 100) / 100

            document.getElementById("monthlyRepaymentOrInterest").innerHTML = "$" + montlyShown
            document.getElementById("totalRepaymentOrInterest").innerHTML = "$" + totalShown

            const getDescriptionArea = document.getElementById("descriptionArea")
            const getResultArea = document.getElementById("resultArea")
            if(!getDescriptionArea.classList.contains("disable")) {
                getDescriptionArea.style.display = "none"
                getDescriptionArea.classList.add("disable")

                getResultArea.style.display = "block"
                // getResultArea.classList.add("")
            }
        } else {
            if(userMortgageAmount == 0) {
                document.getElementById("mortgageAmountAlert").classList.remove("disable")
                document.getElementById("mortgageAmountAlert").classList.add("displayAlert")
                document.getElementById("dollarSign").classList.remove("stale100Background")
                document.getElementById("dollarSign").classList.add("alertBackground")
                document.getElementById("mortgageAmount").classList.remove("inputIdle")
                document.getElementById("mortgageAmount").classList.add("inputAlert")
            } else {
                document.getElementById("mortgageAmountAlert").classList.remove("displayAlert")
                document.getElementById("mortgageAmountAlert").classList.add("disable")
            }
            if(userMortgageTerm == 0) {
                document.getElementById("mortgageTermAlert").classList.remove("disable")
                document.getElementById("mortgageTermAlert").classList.add("displayAlert")
                document.getElementById("years").classList.remove("stale100Background")
                document.getElementById("years").classList.add("alertBackground")
                document.getElementById("mortgageTerm").classList.remove("inputIdle")
                document.getElementById("mortgageTerm").classList.add("inputAlert")
            } else {
                document.getElementById("mortgageTermAlert").classList.remove("displayAlert")
                document.getElementById("mortgageTermAlert").classList.add("disable")
            }
            if(userInterestRate == 0) {
                document.getElementById("interestRateAlert").classList.remove("disable")
                document.getElementById("interestRateAlert").classList.add("displayAlert")
                document.getElementById("percentSymbol").classList.remove("stale100Background")
                document.getElementById("percentSymbol").classList.add("alertBackground")
                document.getElementById("interestRate").classList.remove("inputIdle")
                document.getElementById("interestRate").classList.add("inputAlert")
            } else {
                document.getElementById("interestRateAlert").classList.remove("displayAlert")
                document.getElementById("interestRateAlert").classList.add("disable")
            }
            if(userMortgageType == null) {
                document.getElementById("mortgageTypeAlert").classList.remove("disable")
                document.getElementById("mortgageTypeAlert").classList.add("displayAlert")
            } else {
                document.getElementById("mortgageTypeAlert").classList.remove("displayAlert")
                document.getElementById("mortgageTypeAlert").classList.add("disable")
            }
        }
    })
})