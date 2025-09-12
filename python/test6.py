from sqlalchemy import create_engine
import pandas as pd

# Create some dummy data
df = pd.DataFrame({'name': ['Alice', 'Bob'], 'age': [25, 30]})

# Create an engine (example: SQLite)
engine = create_engine('sqlite:///test.db')

# Save DataFrame to SQL table
df.to_sql('data', con=engine, if_exists='replace', index=False)
