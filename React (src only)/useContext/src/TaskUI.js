import { useContext } from 'react';
import listProvider from './listProvider';

function TaskUI()
{
    const data = useContext(listProvider);
    const listOfData = data.map(
        dataObject => {
            return (
                <li>Title: {dataObject.title}<br/>Date: {dataObject.date}<br/>Time: {dataObject.time}</li>
            )
        }
    )

    return listOfData
}

export default TaskUI;