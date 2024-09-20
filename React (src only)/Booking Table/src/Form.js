import {useState} from 'react'

function Form()
{
    const [date, setDate] = useState("");
    const [time, setTime] = useState("");
    const [guestNumber, setGuestNumber] = useState(1);
    const [occasion, setOccasion] = useState("");

    function handleDateChange(event)
    {
        setDate(event.target.value)
    }

    function hanldeTimeChange(event)
    {
        setTime(event.target.value)
    }

    function handleGuestNumberChange(event)
    {
        setGuestNumber(event.target.value)
    }

    function handleOccasionChange(event)
    {
        setOccasion(event.target.value)
    }

    function handleSubmit(event)
    {
        event.preventDefault()
        var confirmText = "Thank you for your reservation\nHere is the summary\n"
        confirmText += `date: ${date}\n`
        confirmText += `time: ${time}\n`
        confirmText += `guest number: ${guestNumber}\n`
        confirmText += `occasion: ${occasion}`
        alert(confirmText)
        setDate("")
        setTime("")
        setGuestNumber(0)
        setOccasion("")
    }

    return(
        <>
            <h2>Online Reservation</h2>
            <label htmlFor="res-date">Choose date</label>
            <input onChange={handleDateChange} value={date} type="date" id="res-date"/>
            <label htmlFor="res-time">Choose time</label>
            <select onChange={hanldeTimeChange} value={time} id="res-time">
                <option></option>
                <option>17:00</option>
                <option>18:00</option>
                <option>19:00</option>
                <option>20:00</option>
                <option>21:00</option>
                <option>22:00</option>
            </select>
            <label htmlFor="guests">Number of guests</label>
            <input onChange={handleGuestNumberChange} value={guestNumber} type="number" placeholder="1" min="1" max="10" id="guests"/>
            <label htmlFor="occasion">Occasion</label>
            <select onChange={handleOccasionChange} value={occasion} id="occasion">
                <option></option>
                <option>Birthday</option>
                <option>Anniversary</option>
            </select>
            <input onClick={handleSubmit} type="submit" value="Make Your reservation"></input>

            <div>
                <h2>Order Summary</h2>
                <h3>Date: {date}</h3>
                <h3>Time: {time}</h3>
                <h3>Number Of Guest: {guestNumber}</h3>
                <h3>Occasion: {occasion}</h3>
            </div>
        </>
    );
}

export default Form;