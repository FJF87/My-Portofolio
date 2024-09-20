import './App.css';
import TaskUI from './TaskUI';
import taskData from './TaskList';
import listProvider from './listProvider';

function App() {
  return (
    <>
      <h1>My To Do List</h1>
      <ul>
        <listProvider.Provider value={taskData}>
          <TaskUI/>
        </listProvider.Provider>
      </ul>
    </>
  );
}

export default App;
