SELECT * FROM dishes WHERE category_id=2;

SELECT * FROM orders WHERE '2025-11-02'<=order_date AND '2025-11-06'>=order_date;

SELECT SUM(total_price) FROM orders;

SELECT 