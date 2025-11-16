CREATE TABLE dishes(
	id INT PRIMARY KEY,
	name VARCHAR(50),
	category_id INT,
	price INT
);

CREATE TABLE categories(
	id INT PRIMARY KEY,
	category_name VARCHAR(50)
);

CREATE TABLE orders(
	order_id INT PRIMARY KEY,
	dish_id INT,
	order_date DATE,
	quantity INT,
	total_price INT
);

ALTER TABLE dishes ADD FOREIGN KEY (category_id) REFERENCES categories(id);

ALTER TABLE orders ADD FOREIGN KEY (dish_id) REFERENCES dishes(id);



















