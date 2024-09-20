import { useContext, useState } from "react";
import dataContext from "./ContextProvider";

const formStyle = {
    padding: "1vh 2vw 1vh 2vw",
    backgroundColor: "grey",
    margin: "1vh 2vw 1vh 2vw",
    borderStyle: "solid",
    borderWidth: "1%",
    display: "flex",
    flexDirection: "column",
    width: "50vh",
    height: "auto"
}

function Form(e) {
    const data = useContext(dataContext);
    const [comment, setComment] = useState("")

    function handleSubmit(e) {
        e.preventDefault();
        if(comment.length < 11) {
            alert("please provide minimum 10 words");
            console.log(comment);
            return;
        }

        alert("Thank you for sharing your thought");
        setComment("");
    }

    return(
        <div>
            <h1>Comment Section</h1>
            <form onSubmit={handleSubmit} style={formStyle}>
                <label htmlFor="name">Your name</label>
                <input type="text" value={data.name} disabled />
                <label htmlFor="comment">Your Comment</label>
                <input
                    style={{height: "10vh"}}
                    value={comment}
                    type="textarea"
                    id="comment"
                    onChange={e => setComment(e.target.value)}
                />
                <button type="submit" style={{margin: "2%"}}>Share your thought</button>
            </form>
        </div>
    )
}

export default Form;