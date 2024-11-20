import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Custom exception to handle file-related errors
class ContactFileException extends Exception {
    public ContactFileException(String message) {
        super(message);
    }
}

class ContactManager {

    File file;

    ContactManager(String fileName) {
        this.file = new File(fileName);
        try {
            if (!file.exists()) {
                file.createNewFile();  // Create the file if it does not exist
                System.out.println("Created new contacts file: " + fileName);
            }
        } catch (IOException e) {
            System.out.println("Error creating the contacts file: " + e.getMessage());
        }
    }

    // Method to add a contact to the file
		void addContact(String name, String phone) throws ContactFileException {
			
			try {
				FileWriter fileWriter = new FileWriter(file, true);
				BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

				// Writing in the desired format
				bufferedWriter.write("Name: " + name + " and Phone: " + phone);
				bufferedWriter.newLine();

				// Masked output for confirmation
				// String maskedName = name;
				// String maskedPhone = phone;
				System.out.println("Added: Name: " + name + ", Phone: " + phone);
				bufferedWriter.close();
				fileWriter.close();

			} catch (IOException e) {
				throw new ContactFileException("Error writing contact to file: " + e.getMessage());
			}
		}
		   // Method to display all contacts
		void displayContacts() throws ContactFileException {
		
			try {
				FileReader fileReader = new FileReader(file);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				
				String line;
				while ((line = bufferedReader.readLine()) != null) {
					System.out.println(line);  // Printing the line as stored in the file
				}
				 bufferedReader.close();
				 fileReader.close();
			} catch (FileNotFoundException e) {
				throw new ContactFileException("Contact file not found: " + e.getMessage());
			} catch (IOException e) {
				throw new ContactFileException("Error reading contacts from file: " + e.getMessage());
			}
		}
		// Method to search for a contact by name
		void searchContact(String name) throws ContactFileException {
			boolean found = false;
			try {
				FileReader fileReader = new FileReader(file);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				String line;

				while ((line = bufferedReader.readLine()) != null) {
					if (line.startsWith("Name: ") && line.contains(" and Phone: ")) {
						// Split the line to extract the name and phone parts
						String contactName = line.substring(6, line.indexOf(" and Phone:")).trim();
						
						// Check if the extracted name matches the search name
						if (contactName.equalsIgnoreCase(name)) {
							System.out.println("Found: " + line);  // Print the entire line as it is in the file
							found = true;
							break;
						}
					}
				}
				bufferedReader.close();
				 fileReader.close();
				if (!found) {
					System.out.println("Contact not found.");
				}
			} catch (IOException e) {
				throw new ContactFileException("Error searching contact in file: " + e.getMessage());
			}
		}

			// Method to update a contact's phone number
			void updateContact(String name, String newPhone) throws ContactFileException {
				List<String> updatedContacts = new ArrayList<>();
				boolean updated = false;
				try {
					FileReader fileReader = new FileReader(file);
					BufferedReader bufferedReader = new BufferedReader(fileReader);
					String line;
					while ((line = bufferedReader.readLine()) != null) {
						if (line.startsWith("Name: ") && line.contains(" and Phone: ")) {
							// Extract the name from the line
							String contactName = line.substring(6, line.indexOf(" and Phone:")).trim();	
							// Check if the name matches the one we want to update
							if (contactName.equalsIgnoreCase(name)) {
								// Replace with the new phone number in the same format
								String updatedContact = "Name: " + contactName + " and Phone: " + newPhone;
								updatedContacts.add(updatedContact);
								updated = true;
							} else {
								updatedContacts.add(line);
							}
						} else {
							updatedContacts.add(line);  // If format doesn't match, keep line as-is
						}
					}
					bufferedReader.close();
					fileReader.close();
					if (updated) {
						FileWriter fileWriter = new FileWriter(file);
						BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
						for (String contact : updatedContacts) {
							bufferedWriter.write(contact);
							bufferedWriter.newLine();
						}
						System.out.println("Contact updated successfully.");
							
						bufferedWriter.close();
						fileWriter.close();
					} else {
						System.out.println("Contact not found.");
				}
				} catch (IOException e) {
					throw new ContactFileException("Error updating contact: " + e.getMessage());
				}
			}
			
		   // Method to delete a contact by name
		void deleteContact(String name) throws ContactFileException {
			
			List<String> updatedContacts = new ArrayList<>();
			boolean deleted = false;

			try {
				FileReader fileReader = new FileReader(file);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				FileWriter fileWriter = new FileWriter(file);
				BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
				String line;

				while ((line = bufferedReader.readLine()) != null) {
					if (line.startsWith("Name: ") && line.contains(" and Phone: ")) {
						// Extract the name from the line
						String contactName = line.substring(6, line.indexOf(" and Phone:")).trim();

						// Check if the name matches the one we want to delete
						if (contactName.equalsIgnoreCase(name)) {
							deleted = true;  // Skip adding this contact to the list, effectively deleting it
							continue;
						}
					}
					// If the contact name doesn't match or format is incorrect, add line as-is
					updatedContacts.add(line);
				}
				bufferedReader.close();
				fileReader.close();
				
				if (deleted) {
					fileWriter = new FileWriter(file);
					bufferedWriter = new BufferedWriter(fileWriter);
					for (String contact : updatedContacts) {
						bufferedWriter.write(contact);
						bufferedWriter.newLine();
					}
					System.out.println("Contact deleted successfully.");
				} else {
					System.out.println("Contact not found.");
				}
				bufferedWriter.close();
				fileWriter.close();
				
			} catch (IOException e) {
				throw new ContactFileException("Error deleting contact: " + e.getMessage());
			}
		}

    // Main method for demonstration with a switch case menu
    public static void main(String[] args) {
        ContactManager manager = new ContactManager("contacts.txt");
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("\nContact Management System");
            System.out.println("1. Add Contact");
            System.out.println("2. Display Contacts");
            System.out.println("3. Search Contact");
            System.out.println("4. Update Contact");
            System.out.println("5. Delete Contact");
            System.out.println("6. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            try {
                switch (choice) {
                    case 1:
                        System.out.print("Enter name: ");
                        String name = scanner.nextLine();
                        System.out.print("Enter phone: ");
                        String phone = scanner.nextLine();
                        manager.addContact(name, phone);
                        System.out.println("Contact added successfully.");
                        break;

                    case 2:
                        System.out.println("Contacts in file:");
                        manager.displayContacts();
                        break;

                    case 3:
                        System.out.print("Enter name to search: ");
                        String searchName = scanner.nextLine();
                        manager.searchContact(searchName);
                        break;

                    case 4:
                        System.out.print("Enter name to update: ");
                        String updateName = scanner.nextLine();
                        System.out.print("Enter new phone number: ");
                        String newPhone = scanner.nextLine();
                        manager.updateContact(updateName, newPhone);
                        break;

                    case 5:
                        System.out.print("Enter name to delete: ");
                        String deleteName = scanner.nextLine();
                        manager.deleteContact(deleteName);
                        break;

                    case 6:
                        exit = true;
                        System.out.println("Exiting Contact Management System.");
                        break;

                    default:
                        System.out.println("Invalid option. Please try again.");
                }
            } catch (ContactFileException e) {
                System.out.println("An error occurred: " + e.getMessage());
            }
        }

        scanner.close();
    }
}
