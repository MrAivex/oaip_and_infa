SELECT * FROM dishes WHERE category_id=2;

SELECT * FROM orders WHERE '2025-11-02'<=order_date AND '2025-11-06'>=order_date;

SELECT SUM(total_price) FROM orders;

SELECT dish_id, COUNT(dish_id) AS orders_list_sorted FROM orders GROUP BY dish_id ORDER BY orders_list_sorted DESC LIMIT 1;