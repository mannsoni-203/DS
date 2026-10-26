#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[15];
    struct Contact *next;
};

struct Contact *head = NULL;

// Search for a contact by name
struct Contact *findContact(const char name[])
{
    struct Contact *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

// Add a new contact
void addContact(void)
{
    struct Contact *newContact;

    newContact = malloc(sizeof(struct Contact));

    if (newContact == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter contact name: ");
    scanf(" %49[^\n]", newContact->name);

    if (findContact(newContact->name) != NULL)
    {
        printf("Contact already exists!\n");
        free(newContact);
        return;
    }

    printf("Enter phone number: ");
    scanf("%14s", newContact->phone);

    newContact->next = head;
    head = newContact;

    printf("Contact added successfully!\n");
}

// Search for a contact
void searchContact(void)
{
    char name[50];

    printf("Enter name to search: ");
    scanf(" %49[^\n]", name);

    struct Contact *temp = findContact(name);

    if (temp != NULL)
    {
        printf("\nContact Found!\n");
        printf("Name  : %s\n", temp->name);
        printf("Phone : %s\n", temp->phone);
    }
    else
    {
        printf("Contact not found!\n");
    }
}

// Update a contact's phone number
void updateContact(void)
{
    char name[50];

    printf("Enter name to update: ");
    scanf(" %49[^\n]", name);

    struct Contact *temp = findContact(name);

    if (temp != NULL)
    {
        printf("Enter new phone number: ");
        scanf("%14s", temp->phone);

        printf("Contact updated successfully!\n");
    }
    else
    {
        printf("Contact not found!\n");
    }
}

// Delete a contact
void deleteContact(void)
{
    char name[50];

    printf("Enter name to delete: ");
    scanf(" %49[^\n]", name);

    struct Contact *temp = head;
    struct Contact *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Contact not found!\n");
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("Contact deleted successfully!\n");
}

// Display all contacts
void displayContacts(void)
{
    struct Contact *temp = head;
    int count = 1;

    if (head == NULL)
    {
        printf("Contact list is empty!\n");
        return;
    }

    printf("\n========== CONTACT LIST ==========\n");

    while (temp != NULL)
    {
        printf("\nContact %d\n", count);
        printf("Name  : %s\n", temp->name);
        printf("Phone : %s\n", temp->phone);

        temp = temp->next;
        count++;
    }

    printf("\nTotal contacts: %d\n", count - 1);
}

// Main menu
int main(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       CONTACT MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");

            // Release all contacts before exiting
            while (head != NULL)
            {
                struct Contact *temp = head;
                head = head->next;
                free(temp);
            }

            return 1;
        }

        switch (choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                searchContact();
                break;

            case 3:
                updateContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                displayContacts();
                break;

            case 6:
                printf("Thank you for using Contact Management System!\n");
                break;

            default:
                printf("Invalid choice! Please select 1 to 6.\n");
        }

    } while (choice != 6);

    // Free all remaining contacts
    while (head != NULL)
    {
        struct Contact *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
