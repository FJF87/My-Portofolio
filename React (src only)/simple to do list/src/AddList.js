import { useState } from "react";

function AddList({onAddList})
{
    // const [newTodo, setNewTodo] = useState({name: "", description: ""});
    const [newName, setNewName] = useState("");
    const [newDescription, setNewDescription] = useState("");

    // consol e.log("new task name: ", newTodo.name);
    // console.log("new task description: ", newTodo.description);
    return(
        <>
            {/* the input only be able to get 1 character for input, then it will rerender? */}
            <br/>
            <label htmlFor='newTask'>
            New Task
            <input
                id='newTask'
                type='text'
                // value={newTodo.name}
                // onChange={(e) => {
                //   setNewTodo({...newTodo, name: e.target.value});
                // }}
                value={newName}
                onChange={e => setNewName(e.target.value)}
            />
            </label>
            <br/>
            <label htmlFor='newDescription' >
            New Description
            <input
                id='newDescription'
                type='text'
                // value={newTodo.description}
                // onChange={(e) => {
                //   setNewTodo({...newTodo, description: e.target.value});
                // }}
                value={newDescription}
                onChange={e => setNewDescription(e.target.value)}
            />
            </label>
            <input type="submit" onClick={() => {
                setNewName("");
                setNewDescription("");
                onAddList(newName, newDescription)
            }} />
        </>
    )
}

export default AddList;