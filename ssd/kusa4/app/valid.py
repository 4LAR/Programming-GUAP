import re

def is_valid_email(email: str) -> bool:
    """
    Проверяет, является ли адрес электронной почты корректным.

    :param email: Адрес электронной почты для проверки.
    :return: True, если адрес электронной почты корректен, иначе False.
    """

    email_regex = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'

    return re.match(email_regex, email) is not None

def is_valid_password(password: str) -> bool:
    """
    Проверяет длинну пароля (в будущем может быть что-то ещё)
    """
    return len(password) > 0
