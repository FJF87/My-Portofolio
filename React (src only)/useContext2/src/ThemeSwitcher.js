import React, {useContext} from 'react';
import ThemeContext from './Context';

function ThemeSwitcher() {
    const {theme, setTheme} = useContext(ThemeContext);

    const toggleTheme = () => {
        setTheme(prevTheme => (prevTheme === 'light' ? 'dark' : 'light'));
    };

    return(
        <button onClick={toggleTheme}>
            Toggle theme ({theme === 'light' ? 'dark' : 'light'})
        </button>
    );
}

export default ThemeSwitcher;