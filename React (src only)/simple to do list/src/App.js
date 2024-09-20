import './App.css';
import listTodo from './todoList';
import {useState} from 'react';
import { Fragment } from 'react';
import AddList from './AddList';

function App() {
  const [todos, setTodos] = useState(listTodo);

  function handleSubmit(newName, newDescription)
  {
      setTodos(
          [
              ...todos,
              {
                  name: newName,
                  description: newDescription,
                  status: true
              }
          ]
      )
      console.log(todos);
  }

  //with useState - dunno =, haven't done yet
  // const [todos, setTodos] = useState(todo);
  // const [newTodo, setNewTodo] = useState({name: "", description: ""});
  //
  // function ShowList()
  // {
  //   const todoList = todos.map(todo => {
  //     <>
  //       <input type='checkbox' id={todo.name} value={todo.name} />
  //       <label htmlFor={todo.name}>
  //         <h3>name: {todo.name}</h3>
  //         <h4>description: {todo.description}</h4>
  //         <h4>status: {todo.status}</h4>
  //       </label>
  //       <button onClick={() => {
  //         setTodos(!todo.status)
  //       }} />
  //     </>
  //   })
  //   return(todoList)
  // }

  //without usestate - in progress
  function ShowList()
  {
    console.log("todos 0: " + todos[0]);
    console.log("todos 1: " + todos[1]);
    console.log("todos 2: " + todos[2]);
    const todoList = todos.map(todo => {
      if(!todo.status){
        return null
      }
      return(
        <Fragment key={todo.name}>
          <h3>{todo.name}</h3>
          <h4>{todo.description}</h4>
          <button onClick={() => {
            setTodos(todos.filter(actTodo => actTodo.name !== todo.name))
            // setTodos(todos.filter(actTodo => {
            //   if(actTodo.name === todo.name)
            //   {
            //     return todo.status = false
            //   }
            //   return actTodo
            // }))
          }} >delete</button>
          {/* ^ | nah, you can't edit javascript object */}
        </Fragment>
      )
    })
    return todoList
  }

  return (
    <>
      <h1>My To Do List</h1>
      <ShowList/>
      <AddList onAddList={handleSubmit}/>
    </>
  );
}

export default App;
